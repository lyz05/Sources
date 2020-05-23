ls=eval(input())
def cmp(item):
    return (abs(item),item)
ls.sort(key=cmp,reverse=True)
ans = str(ls)
print(ans[1:-1].replace(' ',''))
