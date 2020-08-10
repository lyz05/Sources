import sys

file = open(r".\in.txt", 'r')
sys.stdin = file

while True:
    n = int(input())
    if (n==0):
        exit(0)
    i = 1
    ans = 0
    while n>0:
        if (n&1==0):
            ans += 1
        n>>=1
    print(ans)