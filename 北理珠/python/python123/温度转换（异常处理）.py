s = input()
try:
    num = eval(s[:-1])
except NameError:
    print("试图访问的变量名不存在")
except SyntaxError:
    print("存在语法错误")
else:
    if s[-1] not in ['C', 'c', 'F', 'f']:
        print("输入错误，温度值末位只能是'C','c','F','f'")
    else:
        if s[-1] in ['C', 'c']:
            ans = num * 1.8 + 32
            end = 'F'
        else:
            ans = (num - 32) / 1.8
            end = 'C'
        print("{:.2f}{}".format(ans, end))
