import math
x,y = map(float,input().split(','))
delta = x**3-x*y
if delta>=0 and 2*math.e*y!=0:
    z = (x-math.sqrt(delta))/(2*math.e*y)
    print("{:.2f}".format(z))
else:
    print("公式计算参数有误！")

