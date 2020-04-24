number = input()
try:
    x, y = map(int, input().split(","))
    ans = 1.0 * eval(number[x]) / y
except ZeroDivisionError:
    print("除0错误。")
except IndexError:
    print("索引下标超出范围。")
except:
    print("出错了。")
else:
    print("{}/{} = {:.2f}".format(eval(number[x]), y, ans))
    print("赞！运行正确，没有错误。")
