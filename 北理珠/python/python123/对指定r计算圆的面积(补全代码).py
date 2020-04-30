#-----------------------------------------------------------------------------------------
#请在这里定义getCircleArea(r)函数，计算以r为半径的圆的面积，并返回
import math
def getCircleArea(r):
    return math.pi*r*r

n=int(input())
for i in range(n):
    r=float(input())
    print('{:.2f}'.format(getCircleArea(r)))#调用getCircleArea并打印结果
print('END.')