import org.apache.spark.{HashPartitioner, SparkConf, SparkContext}

/**
 * 对于两个输入文件 A 和 B，编写 Spark 独立应用程序，对两个文件进行合并，并剔除其中重复的内容，得到一个新文件 C。
 */
object RemoveDup {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf().setAppName("RemoveDup").setMaster("local")
    val sc = new SparkContext(conf)
    val files = "file:///D:/git/lyz05/北理珠/scala/res/data4_3/in"
    val rdd = sc.textFile(files)
    val res = rdd.filter(_.trim.length>0)
      .map(line => (line.trim,""))
      .partitionBy(new HashPartitioner(1))
      .groupByKey()
      .sortByKey()
      .keys
    res.saveAsTextFile("file:///D:/git/lyz05/北理珠/scala/res/data4_3/out")
  }
}