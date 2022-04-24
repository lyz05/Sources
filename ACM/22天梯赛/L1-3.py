n,m,x,y = map(int,input().split())
if (x>=m and y<n):
    print('{}-{} {}-{}'.format(x,'Y',y,'Y'))
    print('qing 1 zhao gu hao 2')
elif (y<n and x>=n):
    print('{}-{} {}-{}'.format(x,'Y',y,'N'))
    print('1: huan ying ru guan')

if (y>=m and x<n):
    print('{}-{} {}-{}'.format(x,'Y',y,'Y'))
    print('qing 2 zhao gu hao 1')
elif (x<n and y>=n):
    print('{}-{} {}-{}'.format(x,'N',y,'Y'))
    print('2: huan ying ru guan')

if (x>=n and y>=n):
    print('{}-{} {}-{}'.format(x,'Y',y,'Y'))
    print('huan ying ru guan')
if (x<n and y<n):
    print('{}-{} {}-{}'.format(x,'N',y,'N'))
    print('zhang da zai lai ba')

