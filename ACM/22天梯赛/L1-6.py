def calc(s):
    ret = ''
    for i in range(1,len(s)):
        if (int(s[i])%2==int(s[i-1])%2):
            ret += max(s[i],s[i-1])
    return ret

A = calc(input())
B = calc(input())
if (A==B):
    print(A)
else:
    print(A)
    print(B)