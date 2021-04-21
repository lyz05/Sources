import pandas as pd
import numpy as np

data = pd.read_excel('data/meal_order_detail1_sql.xlsx')
print(data)
data['date'] = pd.to_datetime(data.place_order_time, format="%Y-%m-%d %H:%M:%S")
data['date'] = data['date'].dt.date

data1 = data[['counts', 'amounts', 'date']]
data1 = pd.pivot_table(data1, index='date', aggfunc=np.sum, margins=True)
data1.to_excel('data/PivotDetail1.xlsx', index=True)
print(data1)

data2 = pd.pivot_table(data,values=['amounts'], index='date', aggfunc=np.sum, margins=True, columns='dishes_name')
data2.columns = data2.columns.droplevel(0)
data3 = data2.rename_axis([None],axis=1)
data2.to_excel('data/PivotDetail2.xlsx', index=True)
print(data2)

data3 = pd.pivot_table(data,values=['counts'], index='date', aggfunc=np.sum, margins=True, columns='dishes_name')
data3.columns = data3.columns.droplevel(0)
data3 = data3.rename_axis([None],axis=1)
data3.to_excel('data/PivotDetail3.xlsx', index=True)
print(data3)
