import sys

file = open(r".\in.txt", 'r')
sys.stdin = file

def gcd(n,m):
    if m==0:
        return n
    else:
        return gcd(m,n%m)

try:
    while True:
        input()
        a = input().split()
        N = 0
        M = 1
        for i in a:
            n, m = map(int, i.split('/'))
            N = N*m+M*n
            M *= m
            g = gcd(N,M)
            N /= g
            M /= g
        NUM = N // M
        N %= M
        if NUM==0 and N==0:
            print("0")
        elif NUM==0:
            print("{:.0f}/{:.0f}".format(N, M))
        elif N==0:
            print("{:.0f}".format(NUM))
        else:
            print("{:.0f} {:.0f}/{:.0f}".format(NUM,N,M))
except:
    pass