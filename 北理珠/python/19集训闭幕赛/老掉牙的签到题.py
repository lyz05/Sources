import numpy as np
import sys

file = open(r".\in.txt", 'r')
sys.stdin = file

mo = 1000007
def mod(m):
    m[0][0] %= mo
    m[0][1] %= mo
    m[1][0] %= mo
    m[1][1] %= mo

def power(m, n):
    if n <= 1:
        return mod(m)

    t = mod(power(m, n // 2))
    if n % 2 == 0:
        return mod(np.dot(t, t))

    return mod(np.dot(m, mod(np.dot(t, t))))

def fib(n):
    mat = np.array([[1, 1], [1, 0]])
    t = power(mat, n)[0][1]
    return t


while True:
    try:
        n = int(input())
        if n==0:
            print(0)
        else:
            print(fib(n+1))
    except:
        pass