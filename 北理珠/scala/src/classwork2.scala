import scala.io.StdIn._

object classwork2 {
  def main(args: Array[String]): Unit = {
    println("Please input the score:")
    val grade=readInt()
    grade match{
      case grade if (grade<=100 && grade>=90) => println("优秀")
      case grade if (grade<90 && grade>=80) => println("良好")
      case grade if (grade<80 && grade>=70) => println("中等")
      case grade if (grade<70 && grade>=60) => println("及格")
      case grade if (grade<60) => println("不及格")
      case _ => println("成绩输入有误")
    }
  }
}
