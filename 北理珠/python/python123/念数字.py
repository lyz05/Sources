list = ['ling','yi','er','san','si','wu','liu','qi','ba','jiu','fu']
s = input()
ans = ''
for ch in s:
    if ch=='-':
        ans += list[10]+' '
    else:
        ans += list[ord(ch)-ord('0')]+' '
print(ans[:-1])