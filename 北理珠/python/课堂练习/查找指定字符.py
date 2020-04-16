c = input()
s = input()
num = s.rfind(c)
if num!=-1:
    print("index="+"{:>5d}".format(num))
else:
    print('Not Found')