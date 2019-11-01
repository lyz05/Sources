import sys,os
sys.path.append(os.pardir)
from dataset.mnist import load_mnist
# 第一次调用会花费几分钟......
(x_train, t_train), (x_test, t_test) = load_mnist(flatten=True,normalize=False,one_hot_label=False)
# 输出各个数据的形状
print(x_train.shape) # (60000, 784)

print(t_train.shape) # (60000,)
print(x_test.shape)  # (10000, 784)
print(t_test.shape)  # (10000,)