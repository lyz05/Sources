x,y = map(int,input().split())
cnt = 0
sum = 0
for i in range(x,y+1):
    cnt += 1
    sum += i
    print("{:5}".format(i),end='')
    if cnt%5==0:
        print()
if cnt%5!=0:
    print()
print("Sum = {}".format(sum))