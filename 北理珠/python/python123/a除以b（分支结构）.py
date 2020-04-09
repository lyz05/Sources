a, b = input().split(';')
a = eval(a)
b = eval(b)
if b == 0:
    print('除零错误')
else:
    print('{:.2f}'.format(1.0 * a / b))
