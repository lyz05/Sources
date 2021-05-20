import org.apache.spark.{SparkConf, SparkContext}

import java.sql.{Connection, DriverManager}


object TestRDDIP {

  import com.zaxxer.hikari.HikariConfig
  import com.zaxxer.hikari.HikariDataSource
  import javax.sql.DataSource

  val config = new HikariConfig
  config.setJdbcUrl("jdbc:mysql://localhost:3306/ip2location")
  config.setUsername("root")
  config.setPassword("5137")
  config.addDataSourceProperty("connectionTimeout", "1000") // 连接超时：1秒
  config.addDataSourceProperty("idleTimeout", "60000") // 空闲超时：60秒
  config.addDataSourceProperty("maximumPoolSize", "10") // 最大连接数：10
  val ds = new HikariDataSource(config)

  def search(ip: String, table: String, columnarr: Array[String]): Array[String] = {
    //val table = "ip2location_db5"
    val column = columnarr.mkString("`", "`,`", "`")
    var ret = Array[String]()
    //val column = "country_name, region_name, city_name, latitude, longitude"
    //val resultSet = statement.executeQuery(s"select country_name, region_name, city_name, latitude, longitude, ip_from, ip_to from ip2location_db5 limit $recordNum,${recordNum + 1}")
    val sql = s"SELECT $column FROM ( " +
      s"SELECT * FROM $table WHERE ip_to >= INET_ATON('${ip}') LIMIT 1" +
      s") AS tmp WHERE ip_from <= INET_ATON('$ip')"
    //println(sql)
    var conn: Connection = ds.getConnection()
    val statement = conn.createStatement()
    val resultSet = statement.executeQuery(sql)
    if (resultSet.next()) {
      for (column <- columnarr) {
        //print(column)
        ret = ret :+ resultSet.getString(column)
      }
    } else {
      for (column <- columnarr) {
        ret = ret :+ "-"
      }
    }
    conn.close()
    ret
  }

  def main(args: Array[String]): Unit = {
    //Spark初始化配置文件
    val conf = new SparkConf().setAppName("preHandler").setMaster("local[*]")
    val sc = new SparkContext(conf)
    val iplinesRaw = sc.textFile("file:///D:/bigdata/ipinfo")
    val iplines = iplinesRaw.map(ip => {
      (ip,
        search(ip, "ip2location_db5", Array("country_name", "region_name", "city_name", "latitude", "longitude")),
        search(ip, "ip2location_asn", Array("as")),
      )
    })
    //iplines.coalesce(1).saveAsTextFile("file:///D:/bigdata/ip.csv")
    //print(iplines.count())
    iplines.foreach(x => {
      println(x._1,x._2.mkString(","),x._3.mkString(","))
    })
  }
}
