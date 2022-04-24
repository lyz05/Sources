n,k,s = map(int,input().split())
a = {}
for i in range(n):
    now = tuple(map(int,input().split()))
    if now[0]>=175:
        if a.get(now[0]) is None:
            a[now[0]] = {'fail':0,'accept':0}
        if now[1]>=s:
            a[now[0]]['accept'] += 1
        else:
            a[now[0]]['fail'] += 1
ans = 0
for item in a.values():
    tmp = min(item['fail'],k)
    ans += tmp
    tmp = item['accept']
    ans += tmp
print(ans)
