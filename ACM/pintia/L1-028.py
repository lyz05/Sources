import math

n = int(input())
def judge(num):
    if num==1:
        return False
    for i in range(2,int(math.sqrt(num))):
        if num%i==0:
            return False
    return True
for i in range(n):
    num = int(input())
    if judge(num):
        print('Yes')
    else:
        print('No')
