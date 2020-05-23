s = input()
a = set()
for ch in s:
    a.add(ch)
a = sorted(a)
for ch in a:
    print(ch,end='')
