def Hannoi(n,a,b,c):
    if n==1:
        print(a,'-->',c)
    else:
        Hannoi(n-1,a,c,b)
        Hannoi(1,a,b,c)
        Hannoi(n-1,b,a,c)

n = eval(input())
Hannoi(n,'A','B','C')