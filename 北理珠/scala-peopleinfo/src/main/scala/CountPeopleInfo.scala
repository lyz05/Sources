import org.apache.spark.SparkConf
import org.apache.spark.SparkContext
object CountPeopleInfo{
  def main(args:Array[String]){
    if (args.length<1){
      println("Usage: CountPeopleInfo inputdatafile")
      System.exit(1)
    }
    val conf = new SparkConf().setAppName("CountPeopleInfo").setMaster("local")
    val sc = new SparkContext(conf)
    val lines = sc.textFile(args(0),3)
    val maleInfo = lines.filter(line=>line.contains("M")).map(line=>line.split(" ")).map(t=>(t(1)+" "+t(2)))
    val femaleInfo = lines.filter(line=>line.contains("F")).map(line=>line.split(" ")).map(t=>(t(1)+" "+ t(2)))
    val maleHeightInfo = maleInfo.map(t=>t.split(" ")(1).toInt)
    val femaleHeightInfo = femaleInfo.map(t=>t.split(" ")(1).toInt)
    val lowestMale = maleHeightInfo.sortBy(x=>x,true).first()
    val lowestFemale = femaleHeightInfo.sortBy(p=>p,true).first()
    val highestMale = maleHeightInfo.sortBy(p=>p,false).first()
    val highestFemale = femaleHeightInfo.sortBy(p=>p,false).first()
    println("Number of Male:"+ maleInfo.count())
    println("Number of Female:"+femaleInfo.count())
    println("Lowest Male:"+lowestMale)
    println("Lowest Female:"+lowestFemale)
    println("HighestMale:"+highestMale)
    println("HighestFemale:"+highestFemale)
  }
}