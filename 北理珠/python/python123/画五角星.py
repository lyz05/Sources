#请替换括号中的提示性文字使程序可运行

import turtle

turtle.pensize(4)
turtle.pencolor("yellow")
turtle.fillcolor("red")

#绘制五角星
turtle.begin_fill()
for i in range(5):
    turtle.forward(200)
    turtle.right(144)
    turtle.forward(200)
    turtle.left(144)
turtle.end_fill()

turtle.hideturtle()   #隐藏画笔
turtle.done()         #结束绘制