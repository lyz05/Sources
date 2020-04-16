import math


def prime(x):
    for i in range(2, math.floor(math.sqrt(x))):
        if x % i == 0:
            return False
    return True


s = input()
if s.isalpha() or eval(s) <= 1:
    print('请输入一个大于1的正整数！')
else:
    n = eval(s)
    for i in range(n, 1, -1):
        if prime(i):
            print(i)
            break
