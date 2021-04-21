import time
import requests
from bs4 import BeautifulSoup

def pic_download(url,filename):
    ret = requests.get(url)
    if ret.status_code == 200:
        with open(filename, "wb") as f:
            f.write(ret.content)
    time.sleep(0.1)


def get_response(url):
    response = requests.get(url)
    response.encoding = 'gb2312'
    return response.text


for i in range(1,66+1):
    url = 'http://www.netbian.com/weimei/'
    if i!=1:
        url += 'index_{}.htm'.format(i)
    html = get_response(url)
    soup = BeautifulSoup(html, 'html.parser')  # 文档对象
    for k in soup.find_all('img'):
        if k.has_attr('alt'):
            print(k['src'],k['alt'])
            pic_download(k['src'],'img/{}.jpg'.format(k['alt']))

