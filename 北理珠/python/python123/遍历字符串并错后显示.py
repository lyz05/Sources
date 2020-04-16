s = input()
for ch in s:
    if (ch=='z'):
        exit(0)
    else:
        print(chr(ord(ch)+1),end='')
print(' 哈哈，成功遍历！')