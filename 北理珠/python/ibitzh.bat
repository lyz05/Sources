# IBITZH接口(无法获取accessToken)
curl -d "type=2&accessToken=8e54195d069c4dbea45b7ef1ca4179db" https://hb.zhbit.com/dormitory/getMeterStatus
curl -d "type=1&accessToken=8e54195d069c4dbea45b7ef1ca4179db" https://hb.zhbit.com/dormitory/getMeterStatus
curl -X POST https://hb.zhbit.com/user/loginWxapp/073zk3ll287b784zv3nl2Gihz91zk3ll
# https://hb.zhbit.com/user/loginWxapp/013DIBll2YaD684WFGkl2YxBHp4DIBlg
# 缴费平台
curl -L -d "account=180021104890&password=150850" -H "Content-Type: application/x-www-form-urlencoded" -H "Referer: https://jm.jf.zhbit.com/front/login" -H "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36" "https://jm.jf.zhbit.com/front/tologin"
curl -X POST "https://jm.jf.zhbit.com/meterajax/getbuildinginfo"
curl -d "token=Pu7uqTsAye93ItW6bLmrTkMQXHq2jaFNb3sKDKrZXdxuw5EViol7Y842eGy6Q3Pz%2BlkLQtjrAw6HVbzJJHOAhdBzFU622jAlGjSkgA8AGzY%3D" "https://jm.jf.zhbit.com/meterajax/getbuildinginfo"
curl -d "token=Pu7uqTsAye93ItW6bLmrTkMQXHq2jaFNb3sKDKrZXdxuw5EViol7Y842eGy6Q3Pz%2BlkLQtjrAw6HVbzJJHOAhdBzFU622jAlGjSkgA8AGzY%3D&type=1" "https://jm.jf.zhbit.com/meterajax/getmeterstate"
curl -d "token=Pu7uqTsAye93ItW6bLmrTkMQXHq2jaFNb3sKDKrZXdxuw5EViol7Y842eGy6Q3Pz%2BlkLQtjrAw6HVbzJJHOAhdBzFU622jAlGjSkgA8AGzY%3D&type=2" "https://jm.jf.zhbit.com/meterajax/getmeterstate"
