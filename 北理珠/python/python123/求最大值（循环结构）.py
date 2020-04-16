n = eval(input())
if n <= 0:
    print("ERROR")
else:
    maxx = -1e9 - 7
    for i in range(n):
        num = eval(input())
        maxx = max(maxx, num)
    print("max={}".format(maxx))
