import turtle

turtle.setup(850, 350)
turtle.penup()
turtle.fd(-250)
turtle.pendown()
turtle.pensize(15)
turtle.pencolor("red")
turtle.seth(-40)
rad = 35
angle = 80
neckrad = 15
for i in range(5):
    turtle.circle(rad, angle)
    turtle.circle(-rad, angle)
turtle.circle(rad, angle / 2)
turtle.fd(rad)
turtle.circle(neckrad, 180)
turtle.fd(rad * 2 / 3)
turtle.down()
