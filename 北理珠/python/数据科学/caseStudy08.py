import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression

data_url = ("mtcars.txt")
carsdata = pd.read_csv(data_url, delimiter=' ') #空格分隔读入表格
print(carsdata.head(n=10))    # 打印前10行
print(carsdata.tail(n=10))    # 打印后10行
summary = carsdata.describe()
print(summary) #获得统计信息
#进行最小二乘线性回归分析，对输入的训练数据进行中心化处理
model = LinearRegression(fit_intercept=True)
x = carsdata['wt']
model.fit(x[:, np.newaxis], y)
xfit = np.linspace(1, 6, 32)        #获取均匀间隔的数字，质量由1kg到6kg
yfit = model.predict(xfit[:, np.newaxis])
plt.plot(x, y, "go") #绿色圆点
plt.plot(xfit, yfit, "r--") #红色虚线
plt.title('The relationship between car weight and fuel consumption') #表格标题
plt.xlabel('wt')
plt.ylabel('mpg')
plt.savefig('mtcars.plot.png')
plt.savefig('mtcars.plot.pdf')
plt.show()
