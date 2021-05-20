import org.apache.spark.rdd.RDD
import org.apache.spark.sql.{SQLContext, SparkSession}
import org.apache.spark.{SparkConf, SparkContext}
import org.apache.spark.sql.functions._

object processhandler {

  // 注意：case class必须定义在main方法之外；否则会报错
  case class People(ip: String, user: String, time: String, request: String, status: String, bytes: String, http_content_type: String, referer: String, ua: String, scheme: String)

  //  mysql配置信息
  val url = "jdbc:mysql://localhost:3306/bigdata"
  val prop = new java.util.Properties()
  prop.put("driver", "com.mysql.jdbc.Driver")
  prop.put("user", "root")
  prop.put("password", "5137")

  //Spark初始化配置文件
  private val conf = new SparkConf().setAppName("preHandler").setMaster("local[*]")
  val sc = new SparkContext(conf)
  private val spark = SparkSession.builder()
    .appName("preHandler")
    //.config("spark.some.config.option", "some-value")
    .getOrCreate()
  val sqlContext = new SQLContext(sc)

  import spark.implicits._


  def readDF(src: String): org.apache.spark.sql.DataFrame = {
    sqlContext.read.load(src)
  }

  def main(args: Array[String]) {

    val df = readDF("file:///D:/bigdata/combine")
    //    df.printSchema()
    //    df.show(30)
    //    df.groupBy("scheme").count().show()
    //    df.groupBy("time").count().show()
    //    df.groupBy("status").count().show()
    // Register the DataFrame as a SQL temporary view
    df.createOrReplaceTempView("log")

    //出现404错误的IP次数
    var table = "ip404"
    var ans = df.groupBy("ip", "status").count().filter("status==404").sort(desc("count")).limit(20)
    ans.show()
    //表自动创建
    ans.write.mode("overwrite").jdbc(url, table, prop)

    //访问量与时间分布图
    table = "views"
    val sqlDF = spark.sql("SELECT year,month,day,hour,SUM(bytes) as sum,COUNT(*) as count FROM log GROUP BY year,month,day,hour")
    sqlDF.show()
    sqlDF.write.mode("overwrite").jdbc(url, table, prop)

//    //UA占比 Chart5
//    table = "ua"
//    ans = df.groupBy("ua").count()
//    ans.show()
//    print(ans.count())
//    ans.write.mode("overwrite").jdbc(url, table, prop)

    //请求状态占比 Chart6
    table = "status"
    ans = df.groupBy("status").count()
    ans.show()
    ans.write.mode("overwrite").jdbc(url, table, prop)

    //前十访问来源图 Chart7
    table = "ip"
    ans = df.groupBy("ip").count().sort(desc("count")).limit(10)
    ans.show()
    ans.write.mode("overwrite").jdbc(url, table, prop)

    //https安全协议访问占比 Chart8
    table = "https"
    ans = df.groupBy("scheme").count()
    ans.show()
    ans.write.mode("overwrite").jdbc(url, table, prop)

    //来源操作系统折线图 Chart9
    table = "os"
    ans = df.groupBy("os").count()
    ans.show()
    ans.write.mode("overwrite").jdbc(url, table, prop)

    //请求方法占比图 Chart10
    table = "method"
    ans = df.groupBy("http_method").count()
    ans.show()
    ans.write.mode("overwrite").jdbc(url, table, prop)

    //整个DataFrame表前10项
    table = "df"
    ans = df.limit(10)
    ans.show()
    ans.write.mode("overwrite").jdbc(url, table, prop)

    //请求方法占比图 Chart10
    table = "ip"
    ans = df.groupBy("ip").count()
    ans.show()
    ans.write.mode("overwrite").jdbc(url, table, prop)

    // 按照运营商as聚合
    table = "asname"
    ans = df.groupBy("as").count()
    ans.show()
    ans.write.mode("overwrite").jdbc(url, table, prop)

    //ans.write.format("csv").mode("overwrite").save("file:///D:/result")
    //val sqlDF = spark.sql("SELECT ip,status,COUNT(*) FROM log WHERE status==404 GROUP BY ip,status")
    //sqlDF.show()
  }
}
