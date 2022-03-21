n = eval(input())
s = [input(),input(),input()]
cnt = []
ans = ['xiaoming','xiaowang','xiaoli']
for item in s:
    dic = {}
    for ch in item:
        dic.setdefault(ch,0)
        dic[ch] += 1
    cnt.append(min(max(dic.values())+n,len(item)))
print(cnt)
id = cnt.index(max(cnt))
for i in range(3):
    if i!=id and cnt[i]==cnt[id]:
        print('draw')
        exit(0)
#print(cnt)
print(ans[id])