import numpy as np

data = np.loadtxt("./data/iris_sepal_length.csv", dtype=np.double, delimiter=',')
data = np.sort(np.unique(data))

print("花萼长度表的总和为：", np.sum(data))
print("花萼长度表的累计和为：" ,np.cumsum(data))
print("花萼长度表的均值为：" ,np.mean(data))
print("花萼长度表的标准差为：" ,np.std(data))
print("花萼长度表的方差为：" ,np.var(data))
print("花萼长度表的最小值为：", np.min(data))
print("花萼长度表的最大值为：", np.max(data))

# 花萼长度表的总和为： 210.39999999999998
# 花萼长度表的累计和为： [  4.3   8.7  …   202.5 210.4]
# 花萼长度表的均值为： 6.011428571428571
# 花萼长度表的标准差为： 1.0289443768310533
# 花萼长度表的方差为： 1.0587265306122449
# 花萼长度表的最小值为： 4.3
# 花萼长度表的最大值为： 7.9
