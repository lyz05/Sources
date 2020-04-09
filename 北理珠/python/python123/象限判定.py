x,y=eval(input()),eval(input())
if (x==0 or y==0):
    print('x={}'.format(x))
    print('y={}'.format(y))
elif (x>0 and y>0):
    print('Q1')
elif (x<0 and y>0):
    print('Q2')
elif (x<0 and y<0):
    print('Q3')
else:
    print('Q4')