import re


def num(s):
    if s == '':
        return 1
    elif s == '+':
        return 1
    elif s=='-':
        return -1
    else:
        return eval(s)


def calc(s):
    dic = re.split('[xyz=]', s)
    cnt = 0
    a = [0, 0, 0, 0]
    for item in dic:
        cnt += len(item)
        if cnt < len(s):
            if s[cnt] == 'x':
                a[0] += num(item)
            elif s[cnt] == 'y':
                a[1] += num(item)
            elif s[cnt] == 'z':
                a[2] += num(item)
            elif s[cnt] == '=':
                if (item != ''):
                    a[3] -= eval(item)
        else:
            a[3] += eval(item)
        cnt += 1
    return a

def list_add(a,b):
    c = []
    for i in range(len(a)):
        c.append(a[i]+b[i])
    return c

T = eval(input())
for i in range(1, T+1):
    print("Case #{}:".format(i))
    ans = [0, 0, 0, 0]
    s = input()
    now = calc(s)
    ans = list_add(ans,now)
    s = input()
    now = calc(s)
    ans = list_add(ans,now)
    s = input()
    now = calc(s)
    ans = list_add(ans,now)
    flag = 0
    if ans[0] != 0:
        if (ans[0] > 0 and flag):
            print('+', end='')
        if (ans[0] == -1):
            print('-', end='')
        if (ans[0] != 1 and ans[0] != -1):
            print(str(ans[0]), end='')
        print('x', end='')
        flag = 1
    if ans[1] != 0:
        if (ans[1] > 0 and flag):
            print('+', end='')
        if (ans[1] == -1):
            print('-', end='')
        if (ans[1] != 1 and ans[1] != -1):
            print(str(ans[1]), end='')
        print('y', end='')
        flag = 1
    if ans[2] != 0:
        if (ans[2] > 0 and flag):
            print('+', end='')
        if (ans[2] == -1):
            print('-', end='')
        if (ans[2] != 1 and ans[2] != -1):
            print(str(ans[2]), end='')
        print('z', end='')
        flag = 1
    print('='+str(ans[3]), end='')
    print()
