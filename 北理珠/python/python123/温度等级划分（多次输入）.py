s = input()
while not s.isalpha():
    if s[-1] != 'C':
        print("请以C作为温度值的结尾")
    else:
        num = eval(s[:-1])
        if num <= 0:
            print("寒冷")
        elif num <= 10:
            print("冷")
        elif num <= 20:
            print("凉爽")
        elif num <= 28:
            print("舒适")
        elif num <= 38:
            print("热")
        else:
            print("热死狗啦~~~")
    s = input()
else:
    print("请输入一个数字")
