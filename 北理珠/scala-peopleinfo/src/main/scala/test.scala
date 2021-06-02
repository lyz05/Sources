import org.apache.spark.sql.catalyst.dsl.expressions.StringToAttributeConversionHelper
import org.apache.spark.sql.functions.lit
import org.apache.spark.sql.types.{DoubleType, IntegerType, LongType, StringType, StructField, StructType}
import prehandler.{Dot2LongIP, asndf, ipdf, sqlContext}

import java.text.SimpleDateFormat
import java.util.{Calendar, Date, Locale}

object test {
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
  private val ipdf = sqlContext.read.schema(ipsch).format("csv").load("file:///D:/Download/IP2LOCATION-LITE-DB5.csv")
  private val asndf = sqlContext.read.schema(asnsch).format("csv").load("file:///D:/Download/IP2LOCATION-LITE-ASN.CSV")

  def main(args: Array[String]): Unit = {
    val ipnum = Dot2LongIP("113.140.20.47")
    var asnds = asndf.select("as").filter(s"(ip_from <= $ipnum) AND (ip_to >= $ipnum)")
    var ipds = ipdf.select("country_name", "region_name", "city_name", "latitude", "longitude").filter(s"(ip_from <= $ipnum) AND (ip_to >= $ipnum)")
    val list1 = ipds.toDF("country_name","region_name","city_name","latitude","longitude")
    list1.withColumn("as",lit(asnds.first().get(0)))
    list1.printSchema()
    list1.show()
    val list2 = asnds.first()

  }
}
