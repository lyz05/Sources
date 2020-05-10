# coding: utf-8
import turtle as t
import datetime


def turtlegoto(tx, ty, dir=0):  # 小乌龟平移一段距离
    if (tx > 0):  # 左右方向位移
        t.seth(0)  # 设置角度
        t.fd(tx)  # 前进一段距离
    else:
        t.seth(180)
        t.fd(-tx)
    if (ty > 0):  # 上下方向位移
        t.seth(90)
        t.fd(ty)
    else:
        t.seth(270)
        t.fd(-ty)
    t.seth(dir)  # 设置位移后的方向


def drawNostril():  # 画一个鼻孔
    t.pd()
    t.pencolor(255, 155, 192)  # 设置画笔颜色
    t.fillcolor(160, 82, 45)  # 设置填充颜色
    t.begin_fill()
    t.circle(5)  # 画一个半径为5的圆 鼻孔
    t.end_fill()
    t.pu()


def drawEar(flag):  # 画一只耳朵,flag表示是否为左耳
    t.pd()
    t.begin_fill()
    t.seth(100)  # 设置方向
    t.circle(-50, 50)  # 顺时针画一个半径为-50,圆心角为50°的园 耳朵左半边
    t.circle(-10, 120)  # 耳朵上半边
    t.circle(-50, 54) if flag else t.circle(-50, 56)  # 耳朵右半边 右耳需要多画一点
    t.end_fill()
    t.pu()


def draweye():  # 画一只眼睛
    t.color((255, 155, 192), "white")  # 设置画笔颜色和填充颜色
    t.pd()
    t.begin_fill()
    t.circle(15)  # 眼睛是个白色的圆
    t.end_fill()
    t.pu()
    turtlegoto(-3, 12)
    t.color("black", "black")
    t.pd()
    t.begin_fill()
    t.circle(3)  # 眼球是个黑色的圆
    t.end_fill()
    t.pu()


def drawfoot():  # 画一条腿
    t.pensize(10)  # 设置腿的粗细
    t.color((240, 128, 128))  # 设置腿的颜色
    t.pd()
    t.seth(-90)  # 向下
    t.fd(40)  # 画40长度的线
    t.seth(180)  # 向左
    t.color("black")
    t.pensize(15)  # 重新设置画笔粗细
    t.fd(20)  # 画长度20的线
    t.pu()


def drawPeppaPigNose():
    # 鼻子
    t.color((255, 155, 192), "pink")  # 设置画笔颜色和填充颜色(pink)
    t.goto(-100, 100)  # 画笔前往坐标(-100,100)
    t.pd()  # 下笔
    t.seth(-30)  # 笔的角度为-30° 向右旋转30°
    # 画一个椭圆
    t.begin_fill()  # 外形填充的开始标志
    a = 0.4
    for i in range(120):  # 旋转一周360°=120°*3
        if 0 <= i < 30 or 60 <= i < 90:  # 第四象限和第二象限逐步增大长度
            a = a + 0.08  # 微调单笔长度
            t.lt(3)  # 向左转3度
            t.fd(a)  # 向前走a的步长
        else:  # 第一象限和第三象限逐步减小长度
            a = a - 0.08
            t.lt(3)
            t.fd(a)
    t.end_fill()  # 外形填充的结束标志，依据轮廓填充
    t.pu()  # 提笔
    # 画两个鼻孔
    turtlegoto(10, 25, 90)
    drawNostril()  # 画鼻孔
    turtlegoto(20, 0, 0)
    drawNostril()  # 画鼻孔


def drawPeppaPigHead():
    # 头
    t.color((255, 155, 192), "pink")  # 设置填充颜色和画笔颜色
    turtlegoto(0, 41, 0)
    t.pd()
    t.begin_fill()
    t.seth(0)
    t.circle(-300, 30)  # 顺时针画一个半径为300,圆心角为30°的圆 上半边
    t.circle(-100, 60)  # 上半边
    t.circle(-80, 100)  # 下半边
    t.circle(-150, 20)  # 下半边
    t.circle(-60, 95)  # 下半边
    t.seth(161)  # 重新设置方向
    t.circle(-300, 15)  # 鼻子下边
    t.pu()
    # 画鼻孔的右半边 闭合脸部图形
    t.goto(-100, 100)
    t.pd()
    t.seth(-30)
    a = 0.4
    for i in range(60):  # 只需要画半边
        if 0 <= i < 30 or 60 <= i < 90:
            a = a + 0.08
            t.lt(3)  # 向左转3度
            t.fd(a)  # 向前走a的步长
        else:
            a = a - 0.08
            t.lt(3)
            t.fd(a)
    t.end_fill()
    t.pu()


def drawPeppaPigEar():
    # 耳朵
    t.color((255, 155, 192), "pink")  # 设置填充颜色和画笔颜色
    turtlegoto(70, -7)  # 转移到为多在的位置
    drawEar(True)  # 画左耳
    turtlegoto(30, -12)  # 平移海龟
    drawEar(False)  # 画右耳


def drawPeppaPigEye():
    # 眼睛
    turtlegoto(-95, -20)  # 定位眼睛
    draweye()  # 画眼睛
    turtlegoto(40, -25)  # 定位眼睛
    draweye()  # 画眼睛


def drawPeppaPigGill():
    # 腮
    turtlegoto(65, -95)  # 定位位置
    t.color((255, 155, 192))  # 设置填充颜色
    t.pd()
    t.begin_fill()
    t.circle(30)  # 腮同样是个圆
    t.end_fill()
    t.pu()


def drawPeppaPigMouse():
    # 嘴
    turtlegoto(-100, 15)  # 定位嘴的位置
    t.color(239, 69, 19)  # 设置红色
    t.pd()
    t.seth(-80)  # 设置方向
    t.circle(30, 40)  # 左半边嘴
    t.circle(40, 80)  # 右半边嘴
    t.pu()


def drawPeppaPigBody():
    # 身体
    turtlegoto(-78, -20)  # 定位位置
    t.color("red", (255, 99, 71))  # 画笔红色，填充浅红色
    t.pd()
    t.begin_fill()
    t.seth(-130)
    t.circle(100, 10)  # 画身体左半边上半部分
    t.circle(300, 30)  # 画身体左半边下半部分
    t.seth(0)
    t.fd(230)  # 画身体下半边
    t.seth(90)
    t.circle(300, 30)  # 画身体右半边下半部分
    t.circle(100, 3)  # 画身体右半边上半部分
    t.color((255, 155, 192), (255, 100, 100))
    t.seth(-135)  # 闭合图形 画脸部下半边
    t.circle(-80, 63)
    t.circle(-150, 24)
    t.end_fill()
    t.pu()


def drawPeppaPigHand():
    # 手
    t.color((255, 155, 192))  # 设置手部颜色

    turtlegoto(-27, -40)  # 定位左手臂位置
    t.pd()  # 设置左手臂方向
    t.seth(-160)
    t.circle(300, 15)  # 画一小段弧度 左手臂
    t.pu()
    turtlegoto(0, 15)
    t.pd()
    t.seth(-10)
    t.circle(-20, 90)  # 画手
    t.pu()
    turtlegoto(237, 30)  # 定位右手臂位置
    t.pd()
    t.seth(-20)
    t.circle(-300, 15)  # 画一小段弧度 右手臂
    t.pu()
    turtlegoto(0, 20)
    t.pd()
    t.seth(-170)
    t.circle(20, 90)  # 画手
    t.pu()


def drawPeppaPigfeet():
    # 脚
    turtlegoto(-180, -75)  # 定位
    drawfoot()  # 画左脚
    turtlegoto(90, 40)  # 定位
    drawfoot()  # 画右脚


def drawPeppaPigTail():
    # 尾巴
    t.pensize(4)  # 重新设置画笔粗细
    t.color((255, 155, 192))  # 设置画笔颜色
    turtlegoto(95, 70)  # 定位
    t.pd()
    t.seth(0)
    t.circle(70, 20)  # 画一小段弧
    t.circle(10, 330)  # 画一大段弧度
    t.circle(70, 30)  # 画一小段弧
    t.pu()


def drawPeppaPig():  # 画一个小猪佩奇
    drawPeppaPigNose()  # 画鼻子
    drawPeppaPigHead()  # 画头
    drawPeppaPigEar()  # 画耳朵
    drawPeppaPigEye()  # 画眼睛
    drawPeppaPigGill()  # 画鳃
    drawPeppaPigMouse()  # 画嘴巴
    drawPeppaPigBody()  # 画身体
    drawPeppaPigHand()  # 画手
    drawPeppaPigfeet()  # 画脚
    drawPeppaPigTail()  # 画尾巴


def drawStr(x, y, str, fontsize=15, color='black'):  # 在屏幕上画字符串
    t.pencolor(color)  # 选择颜色
    t.goto(x, y)  # 画笔跳转到（x,y）坐标
    t.pendown()  # 放下画笔
    t.write(str, font=('微软雅黑', fontsize, 'normal'))  # 画字符串
    t.penup()  # 提起画笔


def drawGap():  # 绘制数码管间隔，间隔为2
    t.penup()
    t.fd(2)


def drawLine(draw):  # 绘制单段数码管
    drawGap()  # 画间距
    t.pendown() if draw else t.penup()  # 判断是否要花这一笔
    t.fd(5)  # 画长度为5的一笔
    drawGap()  # 画间距
    t.right(90)


def drawDigit(d):  # 根据数字绘制七段数码管
    drawLine(True) if d in [2, 3, 4, 5, 6, 8, 9] else drawLine(False)  # 画中间一横
    drawLine(True) if d in [0, 1, 3, 4, 5, 6, 7, 8, 9] else drawLine(False)  # 画右下一竖
    drawLine(True) if d in [0, 2, 3, 5, 6, 8, 9] else drawLine(False)  # 画最下面一横
    drawLine(True) if d in [0, 2, 6, 8] else drawLine(False)  # 画左下一竖
    t.left(90)  # 左旋转90°画上部分
    drawLine(True) if d in [0, 4, 5, 6, 8, 9] else drawLine(False)  # 画左上一竖
    drawLine(True) if d in [0, 2, 3, 5, 6, 7, 8, 9] else drawLine(False)  # 画最上面一横
    drawLine(True) if d in [0, 1, 2, 3, 4, 7, 8, 9] else drawLine(False)  # 画右上一竖
    t.left(180)  # 旋转半圈 准备画下一个数字
    t.penup()  # 提笔
    t.fd(10)  # 左右间距


def drawDate(x, y, date, fontsize=15):
    t.pensize(2)  # 设置画笔粗细
    t.goto(x, y)  # 设置画日期的起始位置
    t.seth(0)  # 置方向向右
    t.pencolor("black")  # 设置画笔颜色
    for i in date:  # 提取date中的所有数字
        drawDigit(eval(i))  # 画单个数字


def main():
    t.screensize(400, 300)  # 海龟绘图大小
    t.pensize(4)  # 设置画笔的粗细
    t.colormode(255)  # 设置GBK颜色范围为0-255

    t.setup(840, 500)  # 设置主窗口的大小为840*500
    t.speed(10)  # 设置画笔速度为10
    t.penup()  # 提笔
    drawPeppaPig()  # 画一个佩奇
    drawStr(-400, 200, "刘远哲")  # 画字符串
    drawDate(-400, 170, datetime.datetime.now().strftime('%Y%m%d'))  # 画当前时间
    t.hideturtle()  # 隐藏小海龟
    t.done()  # 停止绘图并显示


main()
