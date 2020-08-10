import sys

file = open(r".\in.txt", 'r')
sys.stdin = file

while True:
    n, m = map(int, sys.stdin.readline().split())
    if (n+m==0):
        break
    l1 = list(sys.stdin.readline())
    l2 = list(sys.stdin.readline())
    if (n!=m):
        print('JiuZhe?')
        continue
    l1.sort()
    l2.sort()
    if l1==l2:
        print('LinBen!')
    else:
        print('JiuZhe?')