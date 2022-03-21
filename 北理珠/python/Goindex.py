import random
import time
import requests
import json
from urllib.parse import quote_plus
user_agent_list = ["Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36",
                   "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36",
                   "Mozilla/5.0 (Windows NT 10.0; WOW64) Gecko/20100101 Firefox/61.0",
                   "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.186 Safari/537.36",
                   "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.62 Safari/537.36",
                   "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.101 Safari/537.36",
                   "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0)",
                   "Mozilla/5.0 (Macintosh; U; PPC Mac OS X 10.5; en-US; rv:1.9.2.15) Gecko/20110303 Firefox/3.6.15",
                   ]
headers = {'User-Agent': random.choice(user_agent_list)}
proxies = {'http': 'http://localhost:7890', 'https': 'http://localhost:7890'}

def post(url, password=None, page_token=None, page_index=0):
    print(url)
    payload = {'q': '', 'password': password,
               'page_token': page_token, 'page_index': page_index}
    payload = json.dumps(payload)
    data = requests.post(url, data=payload, proxies=proxies, headers=headers)
    data.encoding = 'utf=8'
    data = json.loads(data.content)
    return data


def listfiles(url, password=None):
    page_index = 0
    data = post(url=url, password=password, page_index=page_index)
    if 'error' in data:
        print(data['error']['message'])
        exit(0)
    files = data['data']['files']
    while data['nextPageToken'] is not None:
        page_index += 1
        data = post(url=url, password=password,
                    page_token=data['nextPageToken'], page_index=page_index)
        files = files + data['data']['files']
    return files


def dfs(url, password=None):
    ans = []
    files = listfiles(url=url, password=password)
    for item in files:
        if item['mimeType'] == 'application/vnd.google-apps.folder':
            ans += dfs('{}{}/'.format(url, item['name']))
        else:
            url = url.replace('/0:/', '/0:down/')
            ans.append('{}{}'.format(url, item['name']))
    return ans


ans = dfs(url='https://gd.home999.cc/0:/Inbox/pthc/111/', password='')
with open('down.txt', 'w', encoding='utf-8') as f:
    f.write("\n".join(ans))
