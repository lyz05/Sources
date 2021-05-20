import requests
import json
import pandas as pd

def get_response(url):
    response = requests.get(url)
    response.encoding = 'utf-8'
    return response.text

response = get_response('https://www.shanghairanking.cn/api/pub/v1/bcur?bcur_type=11&year=2020')
data = json.loads(response)
with open('result.txt','w') as f:
    for info in data['data']['rankings']:
        print(info['ranking'],info['univNameCn'],info['univNameEn'],info['province'],info['score'],info['rankChange'],file=f)

df = pd.DataFrame(data['data']['rankings'])
df = df[['ranking','univNameCn','univNameEn','province','score','rankChange']]
df.to_excel('大学排名.xls')
print(df)