import random
import string
str = string.ascii_letters + string.digits
n = eval(input())
f = open('key.txt','w+',encoding='utf-8')
for i in range(n):
    ans = ''
    for i in range(24):
        ans += random.choice(str)
    ans = "{}-{}-{}-{}".format(ans[0:6],ans[6:12],ans[12:18],ans[18:24])
    print(ans)
    f.write(ans+'\n')
f.close()