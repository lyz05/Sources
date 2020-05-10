# -*-coding:utf-8 -*-
import turtle as t
import time
import datetime

linelen = 20
gaplen = 5
spacelen = 20
sumlen = linelen + 2 * gaplen
color = [[False] * 7 for i in range(6)]

def drawStr(x, y, str, fontsize=15, color='red'):           # 在屏幕上画字符串
    t.pencolor(color)                                       # 选择颜色
    t.goto(x, y)                                            # 画笔跳转到（x,y）坐标
    t.pendown()                                             # 放下画笔
    t.write(str, font=('微软雅黑', fontsize, 'normal'))      # 画字符串
    t.penup()                                               # 提起画笔

def drawGap():  # 绘制数码管间隔
    t.penup()
    t.fd(gaplen)


def drawLine(x, y, draw, dir, idx, idy):  # 绘制单段数码管,draw是否绘制,dir绘制方向
    if draw == color[idx][idy]:
        return
    color[idx][idy] = draw
    t.goto(x, y)
    t.seth(dir)
    drawGap()  # 画间距
    t.pencolor('red') if draw else t.pencolor('white')  # 判断是否要画这一笔
    t.pendown()
    t.fd(linelen)  # 画长度为linelen的一笔
    drawGap()  # 画间距


def drawDigit(x, y, num, idx):  # 根据数字绘制七段数码管
    # t.goto(x, y)
    # t.seth(0)
    t.showturtle()
    drawLine(x, y, num in [2, 3, 4, 5, 6, 8, 9], 0, idx, 0)  # 画中间一横
    drawLine(x + sumlen, y, num in [0, 1, 3, 4, 5, 6, 7, 8, 9], 270, idx, 1)  # 画右下一竖
    drawLine(x + sumlen, y - sumlen, num in [0, 2, 3, 5, 6, 8, 9], 180, idx, 2)  # 画最下面一横
    drawLine(x, y - sumlen, num in [0, 2, 6, 8], 90, idx, 3)  # 画左下一竖
    drawLine(x, y, num in [0, 4, 5, 6, 8, 9], 90, idx, 4)  # 画左上一竖
    drawLine(x, y + sumlen, num in [0, 2, 3, 5, 6, 7, 8, 9], 0, idx, 5)  # 画最上面一横
    drawLine(x + sumlen, y + sumlen, num in [0, 1, 2, 3, 4, 7, 8, 9], 270, idx, 6)  # 画右上一竖
    t.hideturtle()
    t.penup()  # 提笔
    t.fd(spacelen)  # 左右间距


def drawNum(x, y, lnum, num):
    t.pensize(4)  # 设置画笔粗细
    for i in range(6):  # 提取date中的所有数字
        if lnum[i] != num[i]:
            drawDigit(x + i * (sumlen + spacelen), y, eval(num[i]), i)  # 画单个数字


if __name__ == '__main__':
    t.screensize(400, 300)
    t.colormode(255)
    t.setup(840, 500)
    t.speed(0)
    t.penup()
    drawStr(-(sumlen + spacelen) * 3-120,-10,"当前时间",color='blue')
    lnum = '      '
    while True:
        num = datetime.datetime.now().strftime('%H%M%S')
        drawNum(-(sumlen + spacelen) * 3, 0, lnum, num)
        lnum = num
    t.done()
