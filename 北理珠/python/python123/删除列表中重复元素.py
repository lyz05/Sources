import random
m = eval(input())
n = eval(input())
random.seed(m)
list = []
listsorted = []
for i in range(n):
    num = str(random.randint(0,9))
    list.append(num)
    if num not in listsorted:
        listsorted.append(num)
listsorted.sort()
print(list)
print(listsorted)