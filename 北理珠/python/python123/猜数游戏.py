import random

stdnum = random.randint(0, 30)
# print(stdnum)
count = 0
while True:
    count += 1
    try:
        num = eval(input("请输入您猜测的数字："))
    except:
        print("请输入一个数字！")
    else:
        if num < stdnum:
            print("遗憾，太小了！")
        if num > stdnum:
            print("遗憾，太大了！")
        if num == stdnum:
            print("预测{}次，你猜中了！".format(count))
            break
