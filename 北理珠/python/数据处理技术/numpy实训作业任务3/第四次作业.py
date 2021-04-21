import numpy as np

dname = ['', '美食城', '游乐场', '健身房', '美容院', '台球室', '棋牌室']
sale_avg = np.array([0])
data = np.loadtxt("data.csv", dtype=np.double, delimiter=',', )

print("男性占", 1 - data[:, 1].mean())
print("女性占", data[:, 1].mean())
print("婴幼儿占", np.mean(data[:, 2] <= 6))
print("少儿占", np.mean((data[:, 2] <= 12) & (data[:, 2] > 6)))
print("青少年占", np.mean((data[:, 2] <= 17) & (data[:, 2] > 12)))
print("青年占", np.mean((data[:, 2] <= 45) & (data[:, 2] > 17)))
print("中年占", np.mean((data[:, 2] <= 69) & (data[:, 2] > 45)))
print("老年占", np.mean(data[:, 2] > 69))
for i in range(1, 7):
    print("{}销售：".format(dname[i]), data[:, 4][data[:, 3] == i].sum(), "元")
print("合计销售：", data[:, 4].sum(), "元")

for i in range(1, 7):
    print("{}最大年龄:".format(dname[i]), data[:, 2][data[:, 3] == i].max())
    print("{}最小年龄:".format(dname[i]), data[:, 2][data[:, 3] == i].min())
    print("{}中位数是:".format(dname[i]), np.median(data[:, 2][data[:, 3] == i]))
    print("{}人均消费：".format(dname[i]), data[:, 4][data[:, 3] == i].mean(), "元")
    print("{}女性居多.".format(dname[i]) if data[:, 1][data[:, 3] == i].mean() > 0.5 else "{}男性居多.".format(dname[i]))
    sale_avg = np.append(sale_avg, data[:, 4][data[:, 3] == i].mean())

print('人均消费最高的是：', dname[sale_avg.argmax()], sale_avg.max(),'元')
print('所有店铺人均消费：', data[:, 4].mean(),'元')
data = np.delete(data,np.where(data[:, 3] == 5),axis=0)
print('台球室店铺记录删除后人均消费:', data[:, 4].mean(),'元')

np.savetxt("data去除台球室记录后.csv", data, delimiter=',', fmt='%d')
