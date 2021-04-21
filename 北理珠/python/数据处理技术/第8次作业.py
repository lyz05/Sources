import requests
from bs4 import BeautifulSoup


def get_response(url):
    response = requests.get(url)
    response.encoding = 'utf-8'
    return response.text


list = []
url = 'https://www.jd.com/'
html = get_response(url)
soup = BeautifulSoup(html, 'html.parser')  # 文档对象
for k in soup.find_all('a'):
    # print(k)
    print(k['href'], k.string)
    list.append(k['href'])

print("链接个数:", len(list))
with open('jdallurl.txt', 'w') as f:
    f.write('\n'.join(list))
