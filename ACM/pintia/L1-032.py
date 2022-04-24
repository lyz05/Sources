n,ch = input().split()
s = input()
n = eval(n)
if n>len(s):
    print(ch*(n-len(s))+s)
else:
    print(s[len(s)-n:])