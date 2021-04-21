import pandas as pd


def drop(src, dst, name):
    detail = pd.read_csv(src, encoding='gbk') if '.csv' in src else pd.read_excel(src)
    # detail.dropna(axis=1, how='all', inplace=True)
    s = detail.isna().all() | (detail == detail.iloc[0]).all()
    detail.drop(s[s].index, axis=1, inplace=True)
    print(name)
    print('去除的列的数目为：', s[s].size)
    print('去除后数据的形状为：', detail.shape)
    print('去除后数据的列：', detail.columns)
    detail.to_csv(dst, index=False, encoding='gbk') if '.csv' in dst else detail.to_excel(dst, index=False)


drop('./data/meal_order_detail1_sql.xlsx', './data/meal_order_detail1_d.xlsx', '订单详情meal_order_detail')
drop('./data/meal_order_info.csv', './data/meal_order_info_d.csv', '订单表meal_order_info:')
drop('./data/users.xlsx', './data/users_d.xlsx', '用户信息表users:')
src = './data/meal_order_detail1_sql.xlsx'
detail = pd.read_excel(src)
detail.place_order_time = pd.to_datetime(detail.place_order_time, format="%Y-%m-%d %H:%M:%S")
detail.set_index('place_order_time', drop=True, inplace=True)

print('订单详情表每日的记录数目：')
print(detail.resample('1D').size())
print('订单详情表每日菜品售出数目和销售金额总数为：')
print(detail.resample('1D').sum()[['counts', 'amounts']])
print('订单详情表每日菜品均价为：')
print(detail.resample('1D').mean()[['amounts']])
print('订单详情表每日菜品售价中位数为：')
print(detail.resample('1D').median()[['amounts']])
