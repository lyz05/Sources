import re
import urllib
from urllib.parse import quote
from urllib.parse import unquote

with open('index.html', 'r', encoding='utf-8') as f:
    s = f.read()
with open('index.txt','w',encoding='utf-8') as fout:
    while re.search(r'/data(.*?).mp4', s):
        key = re.search(r'/data(.*?).mp4', s).group()
        value = re.search(r'/data(.*?).mp4', s).group(1)
        fout.write("https://gd.lyz05.workers.dev"+quote(unquote(key))+'\n')
        s = s.replace(key,'123')