A,B = input().split(' ',1)
try:
    A = int(A)
    if (A<1 or A>1000):
        A = '?'
except ValueError:
    A = '?'
try:
    B = int(B)
    if (B<1 or B>1000):
        B = '?'
except ValueError:
    B = '?'
if A!='?' and B!='?':
    C = A+B
else:
    C = '?'

print('{} + {} = {}'.format(A,B,C))