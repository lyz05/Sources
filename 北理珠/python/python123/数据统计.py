import random
n,m = map(int,input().split())
random.seed(10)
dict = {}
for i in range(100):
    num = random.randint(n,m)
    if num in dict:
        dict[num] += 1
    else:
        dict[num] = 1
for i in range(n,m+1):
    if i in dict:
        print("{} {}".format(i,dict[i]))