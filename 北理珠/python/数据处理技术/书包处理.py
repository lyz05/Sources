import pandas as pd
import numpy as np

df = pd.read_excel("书包10页淘宝数据.xlsx")
print("所有列的缺失值数目")
print(df.isnull().sum().sort_values(ascending=False))
print("去除重复项")
print("去重前数目：", df.size)
df.drop_duplicates(inplace=True)
print("去重后数目：", df.size)
print("缺失值填充为0")
df = df.replace(r'^\s*$', np.nan, regex=True)
df['view_sales'] = df['view_sales'].fillna("0")
df['comment_count'] = df['comment_count'].fillna(0)
print("view_sales字段转换为整数")
df['view_sales'] = df['view_sales'].apply(lambda x: x.replace('人付款', '')
                       .replace('万', '*10000')
                       .replace('+', ''))
df['view_sales'] = df['view_sales'].apply(lambda x: eval(x)).astype('int64')
df.to_excel("书包10页淘宝数据-处理后.xlsx")

print("描述信息")
print(df[['view_price','view_sales','comment_count']].describe())
df['sum_sales'] = df['view_price']*df['view_sales']
df = df[['nick','sum_sales']]
df = df.groupby(['nick'],as_index=True)['sum_sales'].sum()
df.to_excel('书包10页淘宝数据-店铺销量.xlsx')
# print("count:\n{}\nmean:\n{}\nstd:\n{}\nmin:\n{}\n".format(df.count(), df.mean(), df.std(), df.min()))
