import numpy as np

n = np.zeros((8, 8), np.int)
n[1::2,::2] = 1
n[::2,1::2] = 1
print("第一题")
print(n)

n = np.random.uniform(0, 1, (10, 5))
print("第二题")
print(n)

a = np.mat([[1, 2], [3, 4]])
b = np.mat([[4, 5], [6, 7]])
print("第三题")
print(a * b)

data = np.loadtxt("./成绩单.csv", dtype=np.int, delimiter=',')
print("第四题")
print("小于0分的分数数目：", np.sum(data < 0))
print("大于100分的分数数目：", np.sum(data > 100))
data[data < 0] = 0
data[data > 100] = 100
print("修正后0分的分数数目：", np.sum(data == 0))
print("修正后100分的分数数目：", np.sum(data == 100))
np.savetxt("修正后的成绩单.csv", data, delimiter=',', fmt='%d')
print(data)
