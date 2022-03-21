n = eval(input())
s = input()
num = [0]
for i in range(1,n+1):
    num.append(num[-1]+eval(s[i-1]))
ans = min(num[-1],n-num[-1])
for i in range(n):
    t = (i - num[i]) + (num[-1] - num[i])
    ans = min(ans,t)
    pass
#print(num)
print(ans)