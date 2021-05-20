import requests
import json
import re
import pandas as pd

result = []
url = 'https://s.taobao.com/search'

headers = {
    'Cookie': 'tracknick=lyz_0515; tg=0; cna=iCnSFzwlaQoCAXBblvIDWFpF; enc=oc2GsaXZ/uJ9BE091ctVJx8AVwK7voFs0kS6duTY7WfYMWxezkbfGQvx1kky8yZR48tzxQL9eGVveXZsofpslg==; thw=cn; hng=CN|zh-CN|CNY|156; t=330adc82e12c33f25de65ab7c9ce9bc2; uc3=nk2=D9rojg18acM=&lg2=Vq8l+KCLz3/65A==&vt3=F8dCuwpjtIEwpqxUBNU=&id2=VyyWs/yGgGrkgg==; lgc=lyz_0515; sgcookie=E1008jYB6YJtGL33omZJlJFzO3FnehdOZkjYgUi/Wh7J+GQTr28NsemS4Gt3L3i06zZdjH7Riiy7cNUwn8rY4WI1cg==; uc4=nk4=0@Dfmo2y5WmJJYjBAFikTi814uLg==&id4=0@VXtZfT2jE6EmoQTlhoE5/wd4OuaX; _cc_=UtASsssmfA==; mt=ci=3_1; _m_h5_tk=bff317c97a0af0a4af872980def2463c_1619434885868; _m_h5_tk_enc=37aa67b93021b55df48d53e19d7cdc5b; cookie2=174e3e5ba4c23f35b2dd1ecbc733f824; _tb_token_=3854810e1e5ef; alitrackid=www.taobao.com; xlly_s=1; lastalitrackid=mooc1-2.chaoxing.com; uc1=cookie14=Uoe1i6vj5Y7QJQ==; JSESSIONID=CC2EDE389676D681FEC2CAF48FA9F6A2; _uab_collina=161942894918398299053122; l=eBxXDVVqq011qMkkBOfZnurza779KIRfguPzaNbMiOCPOO1p58AFW61rMHL9CnGVnsLyR3kEpCzgBuLtNy4ehJpKPJLCgsDLFdTh.; tfstk=cV25BVak5UYSUQ5eUus2auspVxMCZnJS0gg0V5pfAaoMs4Z5iWpZ54xaxEpx6m1..; isg=BDg4VkKCrB0olP3Kf0G6otUmCebKoZwrnQfZ93KpzHMnjdl3GrP3ui2vRYU93VQD; x5sec=7b227365617263686170703b32223a226361363834663234326632666562316438393136373530653265646332643661434e364d6d6f5147454e326d71346a346b6176756c414561444451774e7a59784e4451314d4449374d5367434d4b6546677037382f2f2f2f2f77453d227d',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.116 Safari/537.36',
}

params = {
    'q': '书包',
    's': 0,# 44
    'p4ppushleft': '1-48'
}


def get_response():
    response = requests.get(url, headers=headers,params=params)
    response.encoding = 'utf-8'
    return response.text


for i in range(10):
    params['s'] = i*44
    response = get_response()
    data = json.loads(re.findall(r"g_page_config = (.*);", response)[0])
    data = data['mods']['itemlist']['data']['auctions']
    result = result+data

df = pd.DataFrame(result)
df = df[['raw_title', 'view_price', 'view_sales', 'comment_count', 'user_id', 'nick']]
df.to_excel('taobao书包.xls')
