import requests
r = requests.get('http://www.baidu.com')
print(r.status_code)
r.encoding='utf-8'
print(r.text)
