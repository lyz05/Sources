object Hello {


  def main(args: Array[String]) {
    var sum = 0
    var i = 1
    while (i <= 10000) {
      if (i % 2 == 1) {
        sum += i
      }
      i = i + 1
    }
    println("1.\t1+2+...+10000=" + sum)

    sum = 0
    for (i <- 1 to 10000) {
      if (i % 2 == 1) {
        sum += i
      }
    }
    println("1.\t1+2+...+10000=" + sum)

    println("2.")
    for (i <- 100 to 999) {
      val (a, b, c) = (i / 100, i / 10 % 10, i % 10)
      if (a * a * a + b * b * b + c * c * c == i) {
        println(i)
      }
    }

    println("3.")
    for (i <- 1 to 9) {
      for (j <- 1 to i) {
        print(i + "*" + j + "=" + i * j + "\t")
      }
      println()
    }
  }
}