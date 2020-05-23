ls = eval(input())
ans = []
for item in ls:
    if item != 0:
        ans.append(item)
for i in range(len(ls) - len(ans)):
    ans.append(0)
print(ans)
