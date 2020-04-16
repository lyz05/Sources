s = input()
alpha = 0
num = 0
chinese = 0
blank = 0
for ch in s:
    if ch>='\u4e00' and ch<='\u9fa5':
        chinese += 1
    elif ch.isalpha():
        alpha += 1
    elif ch.isnumeric():
        num += 1
    elif ch==' ':
        blank += 1
print('您输入的字符串中有：{}个空格，{}个数字，{}个中文字符，{}个英文字符，{}个其他字符。'.format(blank,num,chinese,alpha,len(s)-blank-num-chinese-alpha))