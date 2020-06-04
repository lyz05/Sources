import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

#读入数据集
urlf = "women.txt"
women = pd.read_csv(urlf, sep='\s+')

model = LinearRegression(fit_intercept=True)
x = women['height']
y = women['weight']
model.fit(x[:, np.newaxis], y)
xfit = np.linspace(140, 190, 100)
yfit = model.predict(xfit[:, np.newaxis])
plt.plot(xfit, yfit)
plt.scatter(x, y)
#plt.show()
plt.savefig("linearregression.png")
print("Model slope:    ", model.coef_[0])
print("Model intercept:", model.intercept_)
print('預測 height=172, weight為:',
      model.predict(np.array([[172, ]])))
