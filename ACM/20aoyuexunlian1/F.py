t = eval(input())
for i in range(t):
    a,b = map(int,input().split())
    ans = a%b
    if ans==0:
        print(0)
    else:
        print(b-ans)
