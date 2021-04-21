import numpy as np

cname = np.array(['语文', '数学', '英语', '物理', '化学', '历史', '地理', '体育'])

data = np.loadtxt("一维成绩单.csv", dtype=np.double, delimiter=',', )
data = data.reshape((-1, 8))
avg_row = np.around(np.mean(data, axis=1))
avg_col = np.around(np.mean(data, axis=0))
data_new = np.c_[data, avg_row]
np.savetxt("修正后的成绩单.csv", data_new, delimiter=',', fmt='%d')

print("第100行到第102行的三个学生成绩为：", data[100:103])
print("总学生人数是：", np.shape(data)[0])
print("所有分数的平均分为：", np.mean(data))
print("每门课的平均分依次为：", np.mean(data, axis=0))
print("平均分从高到低的课程分别为：", cname[avg_col.argsort()[::-1]])
print("平均分最低分课程是：", cname[np.argmin(avg_col)])
print("平均分最高分课程是：", cname[np.argmax(avg_col)])
print("每门课的最高分依次为：", data.max(axis=0))
print("每门课的最低分依次为：", data.min(axis=0))
print("每门课的不及格率为：", np.mean(data < 60, axis=0))
print("每门课的及格率为：", np.mean((data >= 60) & (data < 70), axis=0))
print("每门课的中等率为：", np.mean((data >= 70) & (data < 80), axis=0))
print("每门课的良好率为：", np.mean((data >= 80) & (data < 90), axis=0))
print("每门课的优秀率为：", np.mean((data >= 90) & (data <= 100), axis=0))
print("按照第1列从低到高排序后前5行数据结果为：", data[data[:, 1].argsort()[:5]])
