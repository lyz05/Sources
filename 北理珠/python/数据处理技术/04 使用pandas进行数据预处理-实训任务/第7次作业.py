import numpy as np
import pandas as pd

df1 = pd.read_excel('./data/meal_order_detail1_sql.xlsx')
df2 = pd.read_excel('./data/meal_order_detail2_sql.xlsx')
df3 = pd.read_excel('./data/meal_order_detail3_sql.xlsx')
df = pd.concat([df1, df2, df3], axis=0, join='inner')
print('三张订单详情表合并后的形状为：', df.shape)

print("进行去重操作前订单详情表的形状为：", df.shape)
df = df.drop_duplicates(subset=None, keep='first', inplace=False)
print("样本去重后订单详情表的形状为：", df.shape)


# 特征去重
def FeatureEquals(df):
    # 定义求取特征是否完全相同的矩阵的函数
    dfEquals = pd.DataFrame([], columns=df.columns, index=df.columns)
    for i in df.columns:
        for j in df.columns:
            dfEquals.loc[i, j] = df.loc[:, i].equals(df.loc[:, j])
    return dfEquals


detEquals = FeatureEquals(df)
detEquals.to_excel('data/detEquals_js.xlsx')
print('通过DataFrame.equals的方法得到特征矩阵并保存到文件detEquals_js.xlsx中.')

lenDet = detEquals.shape[0]
dupCol = []
for k in range(lenDet):
    for l in range(k + 1, lenDet):
        if detEquals.iloc[k, l] & (detEquals.columns[l] not in dupCol):
            dupCol.append(detEquals.columns[l])
print('根据特征矩阵确定需要删除的列有：', dupCol)
df.drop(dupCol, axis=1, inplace=True)
print('进行去重操作后订单详情表的形状为：', df.shape)

print('detail每个特征缺失的数目为：\n', df.isnull().sum())
df.dropna(axis=1, how='any', inplace=True)
print('删除全部数据均为缺失的列后订单详情表的形状为：', df.shape)

print('异常值处理前销售量最小值为：', df['counts'].min())
print('异常值处理前销售量最大值为：', df['counts'].max())
print('异常值处理前售价最小值为：', df['amounts'].min())
print('异常值处理前售价最大值为：', df['amounts'].max())


# 异常值处理
def outRange(Ser):
    QL = Ser.quantile(0.25) - 1.5 * (Ser.quantile(0.75) - Ser.quantile(0.25))
    QU = Ser.quantile(0.75) + 1.5 * (Ser.quantile(0.75) - Ser.quantile(0.25))
    Ser.loc[Ser > QU] = QU
    Ser.loc[Ser < QL] = QL
    return Ser


df['counts'] = outRange(df['counts'].copy())
df['amounts'] = outRange(df['amounts'].copy())
print("异常值处理后销售量最大值为：", df['counts'].max())
print("异常值处理后销售量最小值为：", df['counts'].min())
print("异常值处理后售价最小值为：", df['amounts'].min())
print("异常值处理后售价最大值为：", df['amounts'].max())

# 主键合并订单详情表、订单信息表和客户信息表
order = pd.read_csv('data/meal_order_info.csv', sep=',', encoding='gb18030')
user = pd.read_excel('data/users_info.xlsx')
print('detail表大小：', df.shape)
print('order表大小：', order.shape)
print('user表大小：', user.shape)

order.rename(columns={"info_id": "order_id"}, inplace=True)
merge1 = pd.merge(df, order, on="order_id")
merge1.drop(columns="emp_id_x", inplace=True)
merge1.rename(columns={"emp_id_y": "emp_id"}, inplace=True)
user.rename(columns={"USER_ID": "emp_id"}, inplace=True)
merge2 = pd.merge(merge1, user, on="emp_id")
print("三张表数据主键合并后的大小为：", merge2.shape)
print("合并后的宽表的列：", merge2.columns)
