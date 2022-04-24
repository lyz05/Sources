s = input()
ans = 1
cnt = 0
length = len(s)
for i in s:
    if (i=='-'):
        ans *= 1.5
        length -= 1
    if (i=='2'):
        cnt += 1
ans *= cnt/length
if int(s[-1])%2==0:
    ans *= 2
print('{:.2f}%'.format(ans*100))