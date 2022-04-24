    n = eval(input())
    x,y = 0,0
    for i in input().split():
        if eval(i)%2==1:
            x+=1
        else:
            y+=1
    print('{} {}'.format(x,y))