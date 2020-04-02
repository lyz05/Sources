s = input()
for ch in s:
    if ('a' <= ch and ch <= 'z'):
        print(chr(ord('z')-(ord(ch) - ord('a'))), end='')
    elif ('A' <= ch and ch <= 'Z'):
        print(chr(ord('Z')-(ord(ch) - ord('A'))), end='')
    else:
        print(ch, end='')