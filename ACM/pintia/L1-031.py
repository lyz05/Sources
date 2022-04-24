T = int(input())
for i in range(T):
    n,m = map(int,input().split())
    mm = (n-100)*0.9*2
    if (abs(m-mm)<mm*0.1):
        print('You are wan mei!')
    elif (mm>m):
        print('You are tai shou le!')
    else:
        print('You are tai pang le!')