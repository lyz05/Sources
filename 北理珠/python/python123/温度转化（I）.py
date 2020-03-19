temp = input()
if temp[-1] == 'C':
    ret = eval(temp[:-1]) * 1.8 + 32
    print('{:.2f}F'.format(ret))
else:
    ret = (eval(temp[:-1]) - 32) / 1.8
    print('{:.2f}C'.format(ret))

