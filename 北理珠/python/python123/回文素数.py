import math


def isPrime(x):
    for i in range(2, math.floor(math.sqrt(x))+1):
        if (x % i == 0):
            return False
    return True

def isPalNum(x):
    s = str(x)
    return s == s[::-1]

n = eval(input())
num = 1
cnt = 0
while (cnt<n):
    num += 1
    if (isPrime(num) and isPalNum(num)):
        cnt += 1
        print(num,end=' ')