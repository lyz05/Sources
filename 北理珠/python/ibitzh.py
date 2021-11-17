import requests
import re
import json
import os

from requests.api import head

def get_response(url, payload):
    response = requests.get(url, params=payload)
    response.encoding = 'utf-8'
    return response.text


def serverchan(text, desp):
    SCKEY = os.getenv('SCKEY')
    ret = get_response("https://sc.ftqq.com/" + SCKEY + ".send", {'text': text, 'desp': desp})
    return ret

def is_json(myjson):
    try:
        json.loads(myjson)
    except ValueError:
        return False
    return True

def post(url,payload):
    headers = {
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36',
        'Referer':'https://jm.jf.zhbit.com/front/login'
        }
    r = requests.post(url,data=payload,headers=headers)
    if is_json(r.text):
        return json.loads(r.text)
    else:
        return r.text

# 登录
payload = {'account':'180021104890','password':'150850'}
html = post("https://jm.jf.zhbit.com/front/tologin",payload)
list = re.findall(r"\"token\", \"(.*?)\"", html)
payload = {'token':list[0]}
print(payload)
# 住宿楼栋房间
dic = post("https://jm.jf.zhbit.com/meterajax/getbuildinginfo",payload)
print(dic['buildingData']['ldmc'],dic['buildingData']['fjh'])
# 电费
payload['type'] = 1
dic = post("https://jm.jf.zhbit.com/meterajax/getmeterstate",payload)
msg = "电表状态：{}\n电表余额：{}元\n电表余量：{}度\n".format(dic['zt'],dic['ye'],dic['yl'])
print(msg)
if (eval("{}<20".format(dic['ye']))):
    serverchan("电费不足提醒",msg)
# 水费
payload['type'] = 2
dic = post("https://jm.jf.zhbit.com/meterajax/getmeterstate",payload)
msg = "水表状态：{}\n水表余额：{}元\n水表余量：{}立方\n".format(dic['zt'],dic['ye'],dic['yl'])
print(msg)
if (eval("{}<10".format(dic['ye']))):
    serverchan("水费不足提醒",msg)
payload.pop('type')
# 直饮水
dic = post("https://jm.jf.zhbit.com/drinksajax/getmeterstate",payload)
print("学号：{}\n姓名：{}\n余额：{}\n".format(dic['xh'],dic['xm'],dic['ye']))
# 历史账单
payload['projectid'] = ''
dic = post("https://jm.jf.zhbit.com/ajax/billlist",payload)
for row in dic['bills']['rows']:
    print(row)
payload.pop('projectid')