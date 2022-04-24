n = eval(input())
ans = 0
def fac(n):
    if n==1:
        return 1
    return n*fac(n-1)
for i in range(1,n+1):
    ans += fac(i)
print(ans)