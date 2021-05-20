import pandas as pd
import numpy as np
import re
import os
os.chdir('D:\\我的坚果云\\学校\\北理珠\\20-21-2\\数据处理技术\\期末大作业\\data')

train=pd.read_csv('./ccf_offline_stage1_train.csv')
test=pd.read_csv('./ccf_offline_stage1_test_revised.csv')
# 把没有优惠卷的数据过滤掉
train.dropna(subset=['Coupon_id'],inplace=True)
train.to_csv('tmp.csv')
#训练集
train_1=train.loc[train['Coupon_id']!='',:] #去掉Coupon_id为空的那行数据
#测试集
test_1=test


def hsm(alldata):
    # 计算折扣率
    def countrate(data):
        if ':' in data:
            data_1 = re.search(r'(.*):(.*)', data)  # 以':'分割字符串
            data_2 = list(data_1.group(2))  # 取出第二部分的值（优惠力度）然后用列表把里面的字符分割成单个
            if data_2[0] == '0':  # 该条件表示优惠力度为十元以内
                return float(data_2[1]) / float(data_1.group(1))
            else:  # 该条件表示优惠力度为十元以外
                return float(data_1[2]) / float(data_1.group(1))
        else:
            return  data  # 此行代码代表该数据直接给出了折扣率，直接返回该值

    alldata['Count_rate'] = alldata['Discount_rate'].apply(countrate)

    # 求优惠劵满多少才能使用
    def manjian(data):
        if ':' in data:
            return float(re.search(r'(.*):(.*)', data).group(1))  # 以':'分割字符串，返回第一部分的数字
        else:
            return float(0)  # 此行代码代表该数据直接给出了折扣率，代表使用该优惠卷不需要任何前提就可以用，所以取满减条件为0元

    alldata['Manjian'] = alldata['Discount_rate'].apply(manjian)

    #距离
    alldata['Distance'].replace('','0',inplace=True)

    # 用户领取的优惠券数量
    receive_num = train[['User_id', 'Date_received']].groupby(by='User_id').agg("count").reset_index()
    receive_num.rename(columns={'Date_received': 'Receive_num'}, inplace=True)
    alldata = pd.merge(alldata, receive_num, left_on='User_id', right_on='User_id')

    # 用户在商家领取的优惠券数
    store_receive_num = train[['User_id', 'Merchant_id', 'Date_received']].groupby(['User_id', 'Merchant_id']).agg(
        "count").reset_index()
    store_receive_num.rename(columns={'Date_received': 'Store_receive_num'}, inplace=True)
    alldata = pd.merge(alldata, store_receive_num, on=['User_id', 'Merchant_id'], how='left')
    return alldata

train_1 = hsm(train_1)
test_1 = hsm(test_1)


#添加标签
def label(data):
    if (data['Date_received'] != '' )& (data['Date'] != ''): #这两个if的效果是表示领取优惠券且在15天内使用，即正样本，取为1
        td = pd.to_datetime(data['Date'], format='%Y%m%d') - pd.to_datetime(data['Date_received'], format='%Y%m%d')
        if td <= pd.Timedelta(days=15):
            return 1
    return 0 #剩下的表示领取优惠券未在在15天内使用，即负样本，取为0
train_1['label'] = train_1.apply(label, axis=1) #axis=1:作用于行


def yzr(dataset3, filename='coupon3_feature'):
    # c是不是满减卷(直接优惠为0, 满减为1)
    def is_man_jian(s):
        s = str(s)
        s = s.split(':')
        if len(s) == 1:
            return 0
        else:
            return 1.0

    # c优惠券是不是满减卷(直接优惠为0, 满减为1)
    dataset3['is_man_jian'] = dataset3.Discount_rate.apply(is_man_jian)

    # e每种优惠卷出现的次数
    d = dataset3[['Coupon_id']]
    d['coupon_count'] = 1
    d = d.groupby('Coupon_id').agg('sum').reset_index()  # group().('sum')对优惠券id进行聚合，reset_index()保留优惠券id列
    dataset3 = pd.merge(dataset3, d, on='Coupon_id', how='left')  # 左连接合并

    # f用户领取优惠券的总次数
    d1 = dataset3[dataset3.Coupon_id != 'null'][['User_id']]
    d1['coupon_received'] = 1
    d1 = d1.groupby('User_id').agg('sum').reset_index()
    dataset3 = pd.merge(dataset3, d1, on='User_id', how='left')

    return dataset3


# 对数据集进行coupon_related_feature的提取
train_1 = yzr(train_1, filename='coupon3_feature')
test_1 = yzr(test_1, filename='coupon2_feature')

#训练集存储
train_1.to_csv('traindata22.csv',index=None)
#测试集存储
test_1.to_csv('testdatahsm22.csv',index=None)