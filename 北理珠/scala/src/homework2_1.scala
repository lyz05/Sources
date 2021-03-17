object homework2_1 {
  def main(args: Array[String]): Unit = {
    println("Input q:")
    val q = readInt()
    var sum = 0.0
    var n = 1
    while (sum<q) {
      sum += (n+1)*1.0/n
      n += 1
    }
    println("Sn=",sum)
  }
}
