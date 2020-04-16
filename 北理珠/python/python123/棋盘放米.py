n = eval(input())
while n!=1:
    if n%2==1:
        n = 3*n+1
    else:
        n >>= 1
    print('{:.1f}'.format(n))