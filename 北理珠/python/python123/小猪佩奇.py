# coding: utf-8
import turtle as t
import datetime


def drawPeppaPigNose():
    # 鼻子
    t.penup()                                   # 提笔
    t.goto(-100, 100)                           # 画笔前往坐标(-100,100)
    t.pd()                                      # 下笔
    t.seth(-30)                                 # 笔的角度为-30°
    t.begin_fill()                              # 外形填充的开始标志
    a = 0.4
    for i in range(120):
        if 0 <= i < 30 or 60 <= i < 90:
            a = a + 0.08
            t.lt(3)                             # 向左转3度
            t.fd(a)                             # 向前走a的步长
        else:
            a = a - 0.08
            t.lt(3)
            t.fd(a)
    t.end_fill()                                # 依据轮廓填充
    t.pu()                                      # 提笔
    t.seth(90)                                  # 笔的角度为90度
    t.fd(25)                                    # 向前移动25
    t.seth(0)                                   # 转换画笔的角度为0
    t.fd(10)
    t.pd()
    t.pencolor(255, 155, 192)                   # 设置画笔颜色
    t.seth(10)
    t.begin_fill()
    t.circle(5)                                 # 画一个半径为5的圆
    t.color(160, 82, 45)                        # 设置画笔和填充颜色
    t.end_fill()
    t.pu()
    t.seth(0)
    t.fd(20)
    t.pd()
    t.pencolor(255, 155, 192)
    t.seth(10)
    t.begin_fill()
    t.circle(5)
    t.color(160, 82, 45)
    t.end_fill()


def drawPeppaPigHead():
    # 头
    t.color((255, 155, 192), "pink")
    t.pu()
    t.seth(90)
    t.fd(41)
    t.seth(0)
    t.fd(0)
    t.pd()
    t.begin_fill()
    t.seth(180)
    t.circle(300, -30)  # 顺时针画一个半径为300,圆心角为30°的园
    t.circle(100, -60)
    t.circle(80, -100)
    t.circle(150, -20)
    t.circle(60, -95)
    t.seth(161)
    t.circle(-300, 15)
    t.pu()
    t.goto(-100, 100)
    t.pd()
    t.seth(-30)
    a = 0.4
    for i in range(60):
        if 0 <= i < 30 or 60 <= i < 90:
            a = a + 0.08
            t.lt(3)  # 向左转3度
            t.fd(a)  # 向前走a的步长
        else:
            a = a - 0.08
            t.lt(3)
            t.fd(a)
    t.end_fill()


def drawPeppaPigEar():
    # 耳朵
    t.color((255, 155, 192), "pink")
    t.pu()
    t.seth(90)
    t.fd(-7)
    t.seth(0)
    t.fd(70)
    t.pd()
    t.begin_fill()
    t.seth(100)
    t.circle(-50, 50)
    t.circle(-10, 120)
    t.circle(-50, 54)
    t.end_fill()
    t.pu()
    t.seth(90)
    t.fd(-12)
    t.seth(0)
    t.fd(30)
    t.pd()
    t.begin_fill()
    t.seth(100)
    t.circle(-50, 50)
    t.circle(-10, 120)
    t.circle(-50, 56)
    t.end_fill()

def drawPeppaPigEye():
    # 眼睛
    t.color((255, 155, 192), "white")
    t.pu()
    t.seth(90)
    t.fd(-20)
    t.seth(0)
    t.fd(-95)
    t.pd()
    t.begin_fill()
    t.circle(15)
    t.end_fill()
    t.color("black")
    t.pu()
    t.seth(90)
    t.fd(12)
    t.seth(0)
    t.fd(-3)
    t.pd()
    t.begin_fill()
    t.circle(3)
    t.end_fill()
    t.color((255, 155, 192), "white")
    t.pu()
    t.seth(90)
    t.fd(-25)
    t.seth(0)
    t.fd(40)
    t.pd()
    t.begin_fill()
    t.circle(15)
    t.end_fill()
    t.color("black")
    t.pu()
    t.seth(90)
    t.fd(12)
    t.seth(0)
    t.fd(-3)
    t.pd()
    t.begin_fill()
    t.circle(3)
    t.end_fill()


def drawPeppaPigGill():
    # 腮
    t.color((255, 155, 192))
    t.pu()
    t.seth(90)
    t.fd(-95)
    t.seth(0)
    t.fd(65)
    t.pd()
    t.begin_fill()
    t.circle(30)
    t.end_fill()

def drawPeppaPigMouse():
    # 嘴
    t.color(239, 69, 19)
    t.pu()
    t.seth(90)
    t.fd(15)
    t.seth(0)
    t.fd(-100)
    t.pd()
    t.seth(-80)
    t.circle(30, 40)
    t.circle(40, 80)

def drawPeppaPigBody():
    # 身体
    t.color("red", (255, 99, 71))
    t.pu()
    t.seth(90)
    t.fd(-20)
    t.seth(0)
    t.fd(-78)
    t.pd()
    t.begin_fill()
    t.seth(-130)
    t.circle(100, 10)
    t.circle(300, 30)
    t.seth(0)
    t.fd(230)
    t.seth(90)
    t.circle(300, 30)
    t.circle(100, 3)
    t.color((255, 155, 192), (255, 100, 100))
    t.seth(-135)
    t.circle(-80, 63)
    t.circle(-150, 24)
    t.end_fill()


def drawPeppaPigHand():
    # 手
    t.color((255, 155, 192))
    t.pu()
    t.seth(90)
    t.fd(-40)
    t.seth(0)
    t.fd(-27)
    t.pd()
    t.seth(-160)
    t.circle(300, 15)
    t.pu()
    t.seth(90)
    t.fd(15)
    t.seth(0)
    t.fd(0)
    t.pd()
    t.seth(-10)
    t.circle(-20, 90)
    t.pu()
    t.seth(90)
    t.fd(30)
    t.seth(0)
    t.fd(237)
    t.pd()
    t.seth(-20)
    t.circle(-300, 15)
    t.pu()
    t.seth(90)
    t.fd(20)
    t.seth(0)
    t.fd(0)
    t.pd()
    t.seth(-170)
    t.circle(20, 90)

def drawPeppaPigfoot():
    # 脚
    t.pensize(10)
    t.color((240, 128, 128))
    t.pu()
    t.seth(90)
    t.fd(-75)
    t.seth(0)
    t.fd(-180)
    t.pd()
    t.seth(-90)
    t.fd(40)
    t.seth(-180)
    t.color("black")
    t.pensize(15)
    t.fd(20)
    t.pensize(10)
    t.color((240, 128, 128))
    t.pu()
    t.seth(90)
    t.fd(40)
    t.seth(0)
    t.fd(90)
    t.pd()
    t.seth(-90)
    t.fd(40)
    t.seth(-180)
    t.color("black")
    t.pensize(15)
    t.fd(20)

def drawPeppaPigTail():
    # 尾巴
    t.pensize(4)
    t.color((255, 155, 192))
    t.pu()
    t.seth(90)
    t.fd(70)
    t.seth(0)
    t.fd(95)
    t.pd()
    t.seth(0)
    t.circle(70, 20)
    t.circle(10, 330)
    t.circle(70, 30)
    t.penup()


def drawPeppaPig():                                         #画一个小猪佩奇
    drawPeppaPigNose()
    drawPeppaPigHead()
    drawPeppaPigEar()
    drawPeppaPigEye()
    drawPeppaPigGill()
    drawPeppaPigMouse()
    drawPeppaPigBody()
    drawPeppaPigHand()
    drawPeppaPigfoot()
    drawPeppaPigTail()

def drawStr(x, y, str, fontsize=15, color='red'):           # 在屏幕上画字符串
    t.pencolor(color)                                       # 选择颜色
    t.goto(x, y)                                            # 画笔跳转到（x,y）坐标
    t.pendown()                                             # 放下画笔
    t.write(str, font=('微软雅黑', fontsize, 'normal'))      # 画字符串
    t.penup()                                               # 提起画笔


def drawGap():                                              # 绘制数码管间隔，间隔为2
    t.penup()
    t.fd(2)


def drawLine(draw):                                         # 绘制单段数码管
    drawGap()                                               # 画间距
    t.pendown() if draw else t.penup()                      # 判断是否要花这一笔
    t.fd(5)                                                 # 画长度为5的一笔
    drawGap()                                               # 画间距
    t.right(90)


def drawDigit(d):  # 根据数字绘制七段数码管
    drawLine(True) if d in [2, 3, 4, 5, 6, 8, 9] else drawLine(False)               # 画中间一横
    drawLine(True) if d in [0, 1, 3, 4, 5, 6, 7, 8, 9] else drawLine(False)         # 画右下一竖
    drawLine(True) if d in [0, 2, 3, 5, 6, 8, 9] else drawLine(False)               # 画最下面一横
    drawLine(True) if d in [0, 2, 6, 8] else drawLine(False)                        # 画左下一竖
    t.left(90)                                                                      # 左旋转90°画上部分
    drawLine(True) if d in [0, 4, 5, 6, 8, 9] else drawLine(False)                  # 画左上一竖
    drawLine(True) if d in [0, 2, 3, 5, 6, 7, 8, 9] else drawLine(False)            # 画最上面一横
    drawLine(True) if d in [0, 1, 2, 3, 4, 7, 8, 9] else drawLine(False)            # 画右上一竖
    t.left(180)                                                                     # 旋转半圈 准备画下一个数字
    t.penup()                                                                       # 提笔
    t.fd(10)                                                                        # 左右间距


def drawDate(x, y, date, fontsize=15):
    t.pensize(2)                                                                    # 设置画笔粗细
    t.goto(x, y)                                                                    # 设置画日期的起始位置
    t.seth(0)                                                                       # 置方向向右
    t.pencolor("red")                                                               # 设置画笔颜色
    for i in date:                                                                  # 提取date中的所有数字
        drawDigit(eval(i))                                                          # 画单个数字


def main():
    t.screensize(400, 300)
    t.pensize(4)                                                                    # 设置画笔的粗细
    t.colormode(255)  # 设置GBK颜色范围为0-255
    t.color((255, 155, 192), "pink")  # 设置画笔颜色和填充颜色(pink)
    t.setup(840, 500)  # 设置主窗口的大小为840*500
    t.speed(10)  # 设置画笔速度为10
    t.penup()
    drawPeppaPig()  # 画一个佩奇
    drawStr(-400, 200, "刘远哲")
    drawDate(-400, 170, datetime.datetime.now().strftime('%Y%m%d'))
    t.hideturtle()
    t.done()  # 停止绘图并显示

main()