s = input()
try:
    n=eval(s)
    if (n<0):
        print('-'+s[1:][::-1])
    else:
        print(s[::-1])
except:
    print("输入有误！")