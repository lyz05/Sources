/* SimpleApp.scala */
import org.apache.spark.{SparkConf, SparkContext}
  object SimpleApp {
  def main(args: Array[String]) {
    val logFile = "hdfs://192.168.56.132:9000/user/hadoop/test.txt"
    val conf = new SparkConf().setAppName("Simple Application").setMaster("spark://192.168.56.132:7077")
    val sc = new SparkContext(conf)
    val logData = sc.textFile(logFile, 2)
    val num = logData.count()
    println("这个文件有 %d 行！".format(num))
  }
}
