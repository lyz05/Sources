import math
a,b,c = map(int, input().split(','))
delta = b*b-4*a*c
if delta>=0:
    x1 = (-b-math.sqrt(delta))/(2*a)
    x2 = (-b+math.sqrt(delta))/(2*a)
    if (delta==0):
        print("x={}".format(x1))
    else:
        print("x1={},x2={}".format(x1,x2))
else:
    print("方程没有实数解")