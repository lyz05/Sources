/**
 * 特征类似于接口，可实现多重继承的功能
 */
case class Point(var x: Double, var y: Double) extends Drawable {
  def shift(deltaX: Double, deltaY: Double) {
    x += deltaX; y += deltaY
  }
}

//特征
trait Drawable {
  def draw() {
    println(this.toString)
  }
}

//图形抽象类
abstract class Shape(var point: Point) {
  var r = 4.0

  def moveTo(point2: Point): Unit = {
    point = point2
  }

  // 抽象方法没有方法体
  def zoom(b: Double): Unit

  //圆形构造函数
  def this(cpoint: Point, cr: Double) {
    //第一行必须要先调用默认的构造函数
    this(cpoint: Point)
    this.r = cr
  }

  //直线构造函数
  def this(lpoint: Point, lpoint2: Point) {
    this(lpoint: Point)

  }
}

//圆形
class Circle(point: Point, R: Double) extends Shape(point: Point) with Drawable {
  r = R

  //重写，对图形放大，半径放大
  override def zoom(b: Double): Unit = {
    r = r * b
  }

  //重写，打印
  override def draw(): Unit = {
    var toString = "Circle center:(" + point.x + "," + point.y + ")\t" + "R=" + r
    println(toString)
  }

  //重写，移动
  override def moveTo(point2: Point): Unit = {
    point.x = point2.x
    point.y = point2.y
  }
}

//直线
class Line(point: Point, point1: Point) extends Shape(point: Point) with Drawable {
  //重写，对图形放大
  override def zoom(b: Double): Unit = {
    var xmid = (point1.x + point.x) / 2 //寻找中点坐标
    var ymid = (point1.y + point.y) / 2
    point.x = xmid - (xmid - point.x) * b
    point.y = ymid - (ymid - point.y) * b
    point1.x = xmid + (point1.x - xmid) * b
    point1.y = ymid + (point1.y - ymid) * b
  }

  //重写，打印
  override def draw(): Unit = {
    var toString = "Line:(" + point.x + "," + point.y + ")--" + "（" + point1.x + "," + point1.y + ")"
    println(toString)
  }

  //重写，移动
  override def moveTo(point2: Point): Unit = {
    point1.x = point1.x + point2.x - point.x
    point1.y = point1.y + point2.y - point.y
    point.x = point2.x
    point.y = point2.y
  }
}

object homework2_2 {
  def main(args: Array[String]) {
    val p = new Point(10, 30)
    p.draw;

    val line1 = new Line(Point(0, 0), Point(20, 20))
    line1.draw
    line1.moveTo(Point(5, 5)) //移动到一个新的点
    line1.draw
    line1.zoom(2) //放大两倍
    line1.draw

    val cir = new Circle(Point(10, 10), 5)
    cir.draw
    cir.moveTo(Point(30, 20))
    cir.draw
    cir.zoom(0.5)
    cir.draw
  }
}