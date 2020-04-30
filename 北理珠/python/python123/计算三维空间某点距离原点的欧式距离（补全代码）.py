#-----------------------------------------------------------------------------
#请在这里定义distance函数，计算点（x,y,z）与原点的距离值并返回
import math
def distance(x,y,z):
    return math.sqrt(x*x+y*y+z*z)

x,y,z=input().split(",")
d=distance(float(x),float(y),float(z)) #调用distance函数
print("这个点与原点的距离为{:.2f}。".format(d)) #输出距离值，保留两位小数