s = input()
s = s.upper()
num = eval(s[:-1])
if num >= 1 and num <= 17:
    if s[-1] == 'A' or s[-1] == 'F':
        print('窗口')
    elif s[-1] == 'C' or s[-1] == 'D':
        print('过道')
    elif s[-1] == 'B':
        print('中间')
    else:
        print('输入错误！')
else:
    print('输入错误！')
