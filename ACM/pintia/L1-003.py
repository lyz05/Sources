n = input()
dic = {}
for i in n:
    dic[eval(i)] = dic.get(eval(i),0)+1

for i in range(10):
    if dic.get(i):
        print('{}:{}'.format(i,dic[i]))