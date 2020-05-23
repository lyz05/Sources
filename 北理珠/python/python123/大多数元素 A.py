nums = eval(input())
dict = {}
for num in nums:
    if dict.get(num) is None:
        dict[num] = 1
    else:
        dict[num] += 1
maxx = 0
ans = -1
for num in nums:
    if dict[num]>maxx:
        maxx = dict[num]
        ans = num
print(ans)