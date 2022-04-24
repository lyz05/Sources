dic = {}
n = eval(input())
for i in range(n):
    id, x, y = input().split()
    dic[x] = (id,y)
m = eval(input())
a = input().split()
for x in a:
    (ans1,ans2) = dic[x]
    print("{} {}".format(ans1,ans2))