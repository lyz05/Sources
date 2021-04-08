import org.apache.spark.{SparkConf, SparkContext}

object avg {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf().setMaster("local").setAppName("avg")
    val sc = new SparkContext(conf)
    sc.setLogLevel("ERROR")

    val fourth = sc.textFile("file:///D:/git/lyz05/北理珠/scala/res/data4_4")

    val res = fourth.filter(_.trim().length>0).map(line=>(line.split(" ")(0).trim(),line.split(" ")(1).trim().toInt)).groupByKey().map(x => {
      var num = 0.0
      var sum = 0
      for(i <- x._2){
        sum = sum + i
        num = num +1
      }
      val avg = sum/num
      val format = f"$avg%1.2f".toDouble
      (x._1,format)
    }).collect.foreach(x => println(x._1+" "+x._2))
  }
}
