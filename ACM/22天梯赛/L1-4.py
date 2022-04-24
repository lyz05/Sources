n,m = map(int,input().split())
def fac(x):
    ret = 1
    for i in range(1,x+1):
        ret *= i
    return ret
print(fac(n+m))