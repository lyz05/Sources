import math


while True:
    s = input().split(' ')
    dict = {}
    if s[0] == '#':
        break
    num = math.floor(len(s)/2)
    flag = 1
    for word in s:
        if word not in dict:
            dict[word] = 1
        else:
            dict[word] += 1
        if (dict[word]>num):
            flag = 0
            break
    if (flag):
        print('yes')
    else:
        print('no')