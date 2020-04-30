# ---------------------------------------------------------------------------
# 请在这里定义isPrime函数以完善程序
import math


def isPrime(x):
    for i in range(2, math.floor(math.sqrt(x))+1):
        if (x % i == 0):
            return False
    return True


# 以下已有代码不能修改
num = int(input())  # 读入并转换为整数类型
if isPrime(num):  # 调用isPrime函数判断num是否为素数
    print('yes')
else:
    print('no')
