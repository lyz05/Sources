import scala.math.random
import org.apache.spark._

object student {
  def main(args: Array[String]): Unit = {
    val conf = new SparkConf().setAppName("Student").setMaster("local")
    val sc = new SparkContext(conf)
    sc.setLogLevel("ERROR")
    val data = sc.textFile("file:///D:/git/lyz05/北理珠/scala/res/Data01.txt")
    var num = 0;
    // val wordcount=data.flatMap(_.split(' ')).map((_,1)).groupByKey
    println("学生一共选了课程数："+data.count())
    val student = data.map(row=>row.split(",")(0))
    val distinct_stu = student.distinct() //去重操作
    println("学生一共的数目："+distinct_stu.count) //取得总数


    val course = data.map(row=>row.split(",")(1))//根据，切分的每行数据的第二列进行map
    val distinct_cor = course.distinct()//去重
    println("该系共开设的课程："+distinct_cor.count)//取总数

    println("Tom所选的课程：")
    val tom = data.filter(row=>row.split(",")(0)=="Tom")
    tom.foreach(println)
    tom.map(row=>(row.split(",")(0),row.split(",")(2).toInt))
      .mapValues(x=>(x,1))//mapValues是对值的操作,不操作key使数据变成(Tom,（26,1）)
      .reduceByKey((x,y) => (x._1+y._1,x._2 + y._2))//接着需要按key进行reduce，让key合并当将Tom进行reduce后 这里的(x,y) 表示的是(26,1)(12,1)
      .mapValues(x => (x._1 / x._2))//接着要对value进行操作，用mapValues()就行啦
      .foreach(x => {
        println(x)
      })

    //每名同学选修的课程门数
    val course_each = data.map(row=>(row.split(",")(0),row.split(",")(1)))
    course_each.mapValues(x => (x,1))//数据变为(Tom,(DataBase,1)),(Tom,(Algorithm,1)),(Tom,(OperatingSystem,1)),(Tom,(Python,1)),(Tom,(Software,1))
      .reduceByKey((x,y) => (" ",x._2 + y._2))//数据变为(Tom,( ,5))
      .mapValues(x =>x._2)//数据变为(Tom, 5)
      .foreach(println)

    //计算选DataBase的人数
    val Data_num = data.filter(row=>row.split(",")(1)=="DataBase")
    println(Data_num.count())


    //计算各门平均分
    val average = data.map(row=>(row.split(",")(1),row.split(",")(2).toInt))
    average.mapValues(x=>(x,1)).reduceByKey((x,y) => (x._1+y._1,x._2 + y._2)).mapValues(x => (x._1 / x._2)).foreach(println)


    //使用累加器计算共有多少人选了 DataBase 这门课。
    val pare = data.filter(row=>row.split(",")(1)=="DataBase").map(row=>(row.split(",")(1),1))
    val accum = sc.longAccumulator("Yi_Xia Accumulator")//累加器函数Accumulator
    pare.values.foreach(x => accum.add(x))
    println(accum.value)
  }
}
