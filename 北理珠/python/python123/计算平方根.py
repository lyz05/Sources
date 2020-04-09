import math
n = input()
try:
    n = eval(n)
    print('{}的平方根为{:.2f}。'.format(n, math.sqrt(n)))
except:
    print('请输入正确的参数。')