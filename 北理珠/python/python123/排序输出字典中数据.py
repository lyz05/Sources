dic1 = {'Tom':21,'Bob':18,'Jack':23,'Ana':20}
dic2 = {'李雷':21,'韩梅梅':18,'小明':23,'小红':20}
res = []
n = eval(input())
for i in sorted(dic1.keys())[:n]:
    res.append(i)
print(res)
res = []
for i in sorted(dic2.items(),key=lambda item:item[1])[:n]:
    res.append(i)
print(res)