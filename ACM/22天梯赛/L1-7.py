n,m,q = map(int,input().split())
flag1 = {}
flag2 = {}
for i in range(q):
    t,c = map(int,input().split())
    if (t==0):
        flag1[c] = 1
    else:
        flag2[c] = 1
ans = n*m-(len(flag1)*m+len(flag2)*n-len(flag1)*len(flag2))
print(ans)
        