import requests
import re

headers = {'Accept': '*/*',
           'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.61 Safari/537.36',
           'Accept-Encoding': 'gzip, deflate',
           'Accept-Language': 'zh-CN,zh;q=0.9,zh-TW;q=0.8',
           'Referer':'http://58.213.119.26:8090/login/'}

r = requests.get("http://58.213.119.26:8090/login/")
token = re.search(r'name=\'csrfmiddlewaretoken\' value=\'(.*?)\' />', r.text).group(1)
params = {'username': '13631186569', 'password': 'liliu19990515', 'csrfmiddlewaretoken': token}
print(params)
r = requests.post('http://58.213.119.26:8090/login/', data=params,headers=headers)
print(r.status_code)
print(r.text)
# # with open('index.html','w',encoding='utf-8') as f:
# #     f.write(r.text)
# params = {'answered_state': '2', 'page': '1', 'cloud_platform_id': '4'}
# cookies = {'openlabsession': 'dxf516zqmn6hxo3jdc4kp3av56cd8fjg'}
# r = requests.get("http://58.213.119.26:8090/exam/train/answered/questions/", params=params,cookies=cookies)
# #print(r.text)
