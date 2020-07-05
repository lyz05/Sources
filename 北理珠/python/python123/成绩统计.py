n = eval(input())
list=[]
ok = 0
if n<0:
    print("ERROR")
else:
    for i in range(n):
        num = eval(input())
        if num>=60:
            ok += 1
        list.append(num)
    print(list)
    print("及格 {}\n不及格 {}".format(ok,n-ok))