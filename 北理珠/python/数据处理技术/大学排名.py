import requests
import json

def get_response(url):
    response = requests.get(url)
    response.encoding = 'utf-8'
    return response.text

response = get_response('https://www.shanghairanking.cn/api/pub/v1/bcur?bcur_type=11&year=2020')
data = json.loads(response)
with open('result.txt','w') as f:
    for info in data['data']['rankings']:
        print(info['ranking'],info['univNameCn'],info['univNameEn'],info['province'],info['score'],info['rankChange'],file=f)
