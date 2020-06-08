import csv
import numpy as np
from sklearn.cluster import KMeans

data_path01 = "protein.txt"                 # 读入文件名
with open(data_path01, "r") as rd:
    input01 = csv.reader(rd, delimiter=' ') # 读入表格
    fields = next(input01)                  # 跳过表头
    X = []                                  # 构造数据矩阵
    for row in input01:
        X.append(row)
X = np.array(X)                             # 转换为numpy矩阵
print(X)
X1 = X[:, 1:9]                              # 选取[1:9]中的数据
print(X1)
n_clusters = 5
cls = KMeans(n_clusters).fit(X1)            # 进行KMeans聚类分析
print(cls.labels_)                          # 聚类后每个国家所属位置标签
for i in range(n_clusters):
    print("聚类", i + 1)
    members = cls.labels_ == i
    print("Country:", X[members, 0])        # 聚类国家名
