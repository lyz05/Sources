m = eval(input())
ans = []
try:
    while True:
        ans += m.pop(0)
        for item in m:
            ans.append(item.pop())
        ans += m.pop()[::-1]
        for item in m:
            ans.append(item.pop(0))
except:
    print(ans)