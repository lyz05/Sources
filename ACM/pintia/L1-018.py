s = input()
h,m = s.split(':')
h = int(h)-12
m = int(m)
if m>0:
    h += 1
if h>0:
    print('Dang'*h)
else:
    print('Only {}.  Too early to Dang.'.format(s))