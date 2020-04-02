s = input()
for ch in s:
    if ('a' <= ch and ch <= 'z'):
        print(chr((ord(ch) - ord('a') + 3) % 26 + ord('a')), end='')
    elif ('A' <= ch and ch <= 'Z'):
        print(chr((ord(ch) - ord('A') + 3) % 26 + ord('A')), end='')
    else:
        print(ch, end='')
