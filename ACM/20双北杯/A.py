T = eval(input())
def calc(ch1,ch2):
    x = ord(ch1)-ord('A')
    y = ord(ch2)-ord('A')
    if x>y:
        x,y = y,x
    return min(y-x,x+26-y)


for i in range(1,T+1):
    n = eval(input())
    s = input()
    ans = 1e9+7
    for j in range(0,n-3):
        now = calc(s[j],'A')+calc(s[j+1],'C')+calc(s[j+2],'T')+calc(s[j+3],'G')
        ans = min(ans,now)
    print("Case #{}:".format(i))
    print(ans)
#abcdefghij k lmnopq r stuvwxyzabcdefghij k lmnopq r stuvwxyz
#