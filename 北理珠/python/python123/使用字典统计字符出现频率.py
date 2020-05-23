s = input().split(',')
dict = {}
for snum in s:
    if snum.isdigit():
        num = eval(snum)
        if num not in dict:
            dict[num] = 1
        else:
            dict[num] += 1
    else:
        print('请输入一个数字。')
        exit(0)
print(dict)