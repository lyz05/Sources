#实训2.6 （2）使用urllib访问百度翻译并输出翻译结果
import json
import urllib.request
import urllib.parse
url="https://fanyi.baidu.com/sug/"
headers={
    #"User-Agent":"Mozilla/5.0(Windows NT 10.0;Win64;x64;rv:62.0)Gecko/20100101Firefox/62.0"
}
formData ={
    "kw":"perfect",
}
request=urllib.request.Request(url,headers=headers)
response=urllib.request.urlopen(request,urllib.parse.urlencode(formData).encode())
responseData=json.loads(response.read().decode("unicode_escape"))
showDatas=responseData.get("data")[0].get("v")
print(showDatas)


