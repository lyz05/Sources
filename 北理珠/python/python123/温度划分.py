s=input()
if s[0]=='C':
    s=s[1:]
    n=eval(s)
    if (n<=0):
        print('寒冷')
    elif (n<=10):
        print('冷')
    elif (n<=20):
        print('凉爽')
    elif (n<=28):
        print('舒适')
    elif (n<=38):
        print('热')
    else:
        print('热死狗啦~~~')
else:
    print('请输入正确的温度值。')