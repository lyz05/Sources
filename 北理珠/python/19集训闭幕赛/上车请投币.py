import sys

file = open(r".\in.txt", 'r')
sys.stdin = file

a = [0]*1000
while True:
    n,m = map(int,sys.stdin.readline().split())
    if (n+m==0):
        break
    for i in range(m):
        x,y,z = map(int,sys.stdin.readline().split())
        for i in range(x,y+1):
            a[i] = z
    x,y = map(int,sys.stdin.readline().split())
    last = 0
    ans = 0
    for i in range(x,y+1):
        if (last!=a[i]):
            last = a[i]
            ans += a[i]
    print(ans)
