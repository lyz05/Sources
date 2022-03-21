#a=input().strip()
a="[9,3,7],[6,3]"
a = a.split('],[')
l1 = eval(a[0]+']')
l2 = eval('['+a[1])
now = []
jw = 0
while l1 or l2:
    num1 = l1.pop() if l1 else 0
    num2 = l2.pop() if l2 else 0
    now.append((num1+num2+jw)%10)
    jw = (num1+num2+jw)//10
if jw:
    now.append(jw)
now.reverse()
print("{{{0}}}".format(','.join(str(x) for x in now)))