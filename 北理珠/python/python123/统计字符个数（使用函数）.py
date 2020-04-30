# 请在下面定义count_letter函数
def count_letter(s, stdch):
    ret = 0
    for ch in s:
        if (ch == stdch):
            ret += 1
    return ret


string = input()  # 读入字符串
char = input()  # 读入字符
print(count_letter(string, char))  # 调用count_letter函数统计char在string中出现的次数
