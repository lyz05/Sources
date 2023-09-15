def show(num):
    return "{}:{}:{}".format(str(num//3600).zfill(2),str(num%3600//60).zfill(2),str(num%60).zfill(2))

a = []
n = int(input())
for i in range(n):
    st,en = input().split(' - ')
    a.append(st)
    a.append(en)
print(a.sort)

