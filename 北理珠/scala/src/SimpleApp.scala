/* SimpleApp.scala */
import org.apache.spark.{SparkConf, SparkContext}
  object SimpleApp {
  def main(args: Array[String]) {
    val logFile = "file:///D:/git/lyz05/北理珠/scala/res/test1.txt"
    val conf = new SparkConf().setAppName("Simple Application").setMaster("local")
    val sc = new SparkContext(conf)
    val logData = sc.textFile(logFile, 2)
    val num = logData.count()
    println("这个文件有 %d 行！".format(num))
  }
}
