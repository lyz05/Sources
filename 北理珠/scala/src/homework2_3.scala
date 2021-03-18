object homework2_3 {
  def main(args: Array[String]): Unit = {
    println("第一组测试数据")
    runner("res/test1.txt")
    println("第二组测试数据")
    runner("res/test2.txt")
  }

  def runner(filename: String) {
    val inputFile = scala.io.Source.fromFile(filename)
    //”\\s+“是字符串正则表达式，将每行按空白字符（包括空格/制表符）分开
    // 由于可能涉及多次遍历，同 toList 将 Iterator 装为 List
    // originalData 的类型为 List[Array[String]]
    val originalData = inputFile.getLines.map {
      _.split("\\s+")
    }.toList
    val courseNames = originalData.head.drop(2) //获取第一行中的课程名,去除前两个id与Gender字段
    val allStudents = originalData.tail // 去除第一行剩下的数据
    val courseNum = courseNames.length

    // 统计函数，参数为需要常用统计的行
    //用到了外部变量 courseNum，属于闭包函数
    def statistc(lines: List[Array[String]]) = {
      // for 推导式，对每门课程生成一个三元组，分别表示总分，最低分和最高分
      (for (i <- 2 to courseNum + 1) yield {
        // 取出需要统计的列
        val temp = lines map {
          elem => elem(i).toDouble
        }
        (temp.sum, temp.min, temp.max)
      }) map { case (total, min, max) => (total / lines.length, min, max)
      } // 最后一个 map 对 for 的结果进行修改，将总分转为平均分
    }

    // 输出结果函数
    def printResult(theresult: Seq[(Double, Double, Double)]) {
      // 遍历前调用 zip 方法将课程名容器和结果容器合并，合并结果为二元组容器
      (courseNames zip theresult) foreach {
        case (course, result) =>
          println(f"${course + ":"}%-10s${result._1}%5.2f${result._2}%8.2f${result._3}%8.2f")
      }
    }

    // 分别调用两个函数统计全体学生并输出结果
    val allResult = statistc(allStudents)
    println("course average min max")
    printResult(allResult)

    //按性别划分为两个容器
    val (maleLines, femaleLines) = allStudents partition {
      _ (1) == "male"
    }
    // 分别调用两个函数统计男学生并输出结果
    val maleResult = statistc(maleLines)
    println("course average min max")
    printResult(maleResult)
    // 分别调用两个函数统计女学生并输出结果
    val femaleResult = statistc(femaleLines)
    println("course average min max")
    printResult(femaleResult)
  }
}