import TestRDDIP.search
import org.apache.spark.rdd.RDD
import org.apache.spark.sql.{SQLContext, SparkSession}
import org.apache.spark.{SparkConf, SparkContext}
import org.apache.spark.sql.functions.to_timestamp
import org.apache.spark.sql.types._
import processhandler.spark

import java.text.SimpleDateFormat
import java.util.{Calendar, Locale}

object prehandler {

  // 注意：case class必须定义在main方法之外；否则会报错
  case class Row(ip: String,
                 user: String,
                 year: Int,
                 month: Int,
                 day: Int,
                 hour: Int,
                 min: Int,
                 second: Int,
                 http_method: String,
                 http_path: String,
                 http_version: String,
                 status: Int,
                 bytes: Long,
                 http_content_type: String,
                 referer: String,
                 os: String,
                 scheme: String,
                 as:String,
                 country_name:String,
                 region_name:String,
                 city_name:String,
                 latitude:String,
                 longitude:String)

  //Spark初始化配置文件
  private val conf = new SparkConf().setAppName("preHandler").setMaster("local[*]")
  val sc = new SparkContext(conf)
  private val spark = SparkSession.builder()
    .appName("preHandler")
    //.config("spark.some.config.option", "some-value")
    .getOrCreate()
  val sqlContext = new SQLContext(sc)

  import spark.implicits._

  //正则表达式
  private val pattern = "^(.*?) - (.*?) \\[(.*?)\\] \"(.*?)\" (\\d+) (\\d+) \"(.*?)\" \"(.*?)\" \"(.*?)\" - (.*?)$".r.unanchored

  //有关ip数据库的函数
  private val ipsch = StructType(
    StructField("ip_from", LongType) ::
      StructField("ip_to", LongType) ::
      StructField("country_code", StringType) ::
      StructField("country_name", StringType) ::
      StructField("region_name", StringType) ::
      StructField("city_name", StringType) ::
      StructField("latitude", DoubleType) ::
      StructField("longitude", DoubleType) ::
      Nil
  )

  private val asnsch = StructType(
    StructField("ip_from", LongType) ::
      StructField("ip_to", LongType) ::
      StructField("cidr", StringType) ::
      StructField("asn", IntegerType) ::
      StructField("as", StringType) ::
      Nil
  )
  private val ipdf = sqlContext.read.schema(ipsch).format("csv").load("file:///D:/bigdata/IP2LOCATION-LITE-DB5.csv")
  private val asndf = sqlContext.read.schema(asnsch).format("csv").load("file:///D:/bigdata/IP2LOCATION-LITE-ASN.CSV")

  def Dot2LongIP(ipstring: String): Long = {
    //判断是否为IPV6
    if (ipstring.contains(":")) {
      0
    } else {
      val ipAddressInArray = ipstring.split("\\.")
      var result = 0L
      for (x <- 3 to 0 by -1) {
        val ip = ipAddressInArray(3 - x).toLong
        result |= ip << (x << 3)
      }
      result
    }
  }


  def readRdd(src: String): RDD[String] = {
    //读取所有日志数据并合并成一个文件,并进行过滤
    val linesRaw = sc.textFile(src)
    //  .coalesce(1)
    println("日志文件总行数(过滤前)：" + linesRaw.count())
    val lines = linesRaw
      //过滤非法数据
      .filter {
        x => {
          val arr = x.split("- -")
          arr.length!=3  && !arr(0).contains("-")
        }
      }

    println("日志文件总行数(过滤后)：" + lines.count())
    //查看前10行记录
    println("前10行数据")
    lines.take(10).foreach(println)
    lines
  }

  def generateDF(lines: RDD[String]): org.apache.spark.sql.DataFrame = {
    //    提取每行记录的字段
    val processRDD = lines.map {
      x => {
        val pattern(ip, user, time, request, status, bytes, http_content_type, referer, ua, scheme) = x
        //request处理
        val requests = request.split(" ")
        //val program = ua.split(" ")(0).split('/')
        var os = "-"
        if (ua.contains("Windows NT")) {
          os = "Windows"
        } else if (ua.contains("Darwin")) {
          os = "Apple"
        } else if (ua.contains("Linux")) {
          os = "Linux"
        } else if (ua.contains("bot")) {
          os = "bot"
        }
        //time处理
        val sdf = new SimpleDateFormat("dd/MMM/yyyy:HH:mm:ss Z", Locale.ENGLISH)
        val calendar = Calendar.getInstance()
        val ts = sdf.parse(time)
        calendar.setTime(ts)
        val year = calendar.get(Calendar.YEAR).toString
        val month = (calendar.get(Calendar.MONTH) + 1).toString
        val day = calendar.get(Calendar.DAY_OF_MONTH).toString
        val hour = calendar.get(Calendar.HOUR_OF_DAY).toString
        val min = calendar.get(Calendar.MINUTE).toString
        val second = calendar.get(Calendar.SECOND).toString
        //ip处理
        val asnds = search(ip, "ip2location_asn", Array("as"))
        val ipds = search(ip, "ip2location_db5", Array("country_name", "region_name", "city_name", "latitude", "longitude"))
        Array(ip, user, year, month, day, hour, min, second, requests(0), requests(1), requests(2), status, bytes, http_content_type, referer, os, scheme, asnds(0), ipds(0), ipds(1), ipds(2), ipds(3), ipds(4))
      }
    }
    //println("提取字段解析为数组类型")
    //    RDD[Array[String]]转DataFrame
    var df = processRDD.map(x => Row(x(0), x(1), x(2).toInt, x(3).toInt, x(4).toInt, x(5).toInt, x(6).toInt, x(7).toInt, x(8), x(9), x(10), x(11).toInt, x(12).toLong, x(13), x(14), x(15), x(16),x(17),x(18),x(19),x(20),x(21),x(22))) //将rdd的每一行都转换成了一个people
      .toDF //必须先导入import spark.implicits._  不然这个方法会报错
    //val ts = to_timestamp($"time", "dd/MMM/yyyy:HH:mm:ss Z")
    //df = df.withColumn("time", ts)
    df
  }

  def readDF(src: String): org.apache.spark.sql.DataFrame = {
    sqlContext.read.load(src)
  }

  def main(args: Array[String]) {

    //val lines = readRdd("hdfs://192.168.56.132:9000/user/hadoop/nginx-access-log/*mirrors/*.gz")
    //val lines = readRdd("hdfs://192.168.56.132:9000/user/hadoop/nginx-access-log/nanomirrors/*.gz")
    val lines = readRdd("file:///D:/bigdata/*mirrors/aosp.log-20210501.gz")
    val df = generateDF(lines)

    //    println("写到文件")
    //    lines.saveAsTextFile("file:///D:/combine")

    //写入DataFrame
    df.write.format("parquet")
      .mode("overwrite")
      .option("header", "true")
      .save("file:///D:/bigdata/combine")
    //val df = readDF("file:///D:/combine")
    df.printSchema()
    df.show(10,10)


    //    println("计算每个字段中元素出现的次数")
    //    for (i <- 0 to 8) {
    //      val tmpRDD = processRDD.map(x => x(i)).countByValue().take(20).foreach(println)
    //    }
    //val fields = schemaString.split(",").map(fieldName => StructField(fieldName, StringType, nullable = true))
    //    val schemeRDD = processRDD.map(x=>(x._9,1)).reduceByKey(_+_).sortBy(_._2,false)
    //    val uaRDD = processRDD.map(x=>(x._8,1)).reduceByKey(_+_).sortBy(_._2,false)
    //    val refererRDD = processRDD.map(x=>(x._7,1)).countByValue()
    //    schemeRDD.foreach(println)
    //    uaRDD.foreach(println)
    //    refererRDD.foreach(println)
    //processRDD.

    //      .take(20).foreach(x =>{
    //      println(x._9)
    //    })

    //合并到一个文件
    //      .saveAsTextFile("file:///D:/combine")
    //    FileSystem.get( sc.hadoopConfiguration )
    //      .listStatus( new Path("hdfs://192.168.56.132:9000/user/hadoop/nginx-access-log/nanomirrors/"))
    //      .foreach( x => println(x.getPath ))

  }


  def RegexTest(): Unit = {
    //取其中一条记录为例，分析，提取字段
    var s = "120.31.66.169 - - [30/Apr/2021:00:07:55 +0800] \"GET /platform/frameworks/opt/car/setupwizard/info/refs?service=git-upload-pack HTTP/1.1\" 301 185 \"text/html\" \"-\" \"git/2.7.4 (Linux) git-repo/2.13.8\" - http"
    val pattern(ip, time, request, status, bytes, http_content_type, referer, ua, scheme) = s
    println("单行记录解析结果")
    println(ip, time, request, status, bytes, http_content_type, referer, ua, scheme)
    //单行异常数据处理
    //异常数据为本应该为两行记录的数据被合并到一行，需要找到特征处理
    s = "210.21.223.158 - - [30/Apr/2021:19:08:17 +0800] \"GET /platform/external/libcap/info/refs?service=git-upload-pack HTTP/1.1\"210.21.223.6 - - [30/Apr/2021:19:10:16 +0800] \"GET /platform/external/python/pyparsing/info/refs?service=git-upload-pack HTTP/1.1\" 200 37865 \"application/x-git-upload-pack-advertisement\" \"-\" \"git/2.1.4\" - https"
  }
}
