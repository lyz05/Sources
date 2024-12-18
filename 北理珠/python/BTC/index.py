# -*- coding: utf-8 -*-
import json
import time
import requests
import matplotlib.pyplot as plt
import pandas as pd


def get_response(url, payload):
    response = requests.get(url, params=payload)
    response.encoding = 'utf-8'
    return response.text


def serverchan(text, desp):
    SCKEY = 'SCU99687T71640fcac167ee340005ec9eb0dac0605ecfc826a2443'
    ret = get_response("https://sc.ftqq.com/" + SCKEY + ".send", {'text': text, 'desp': desp})
    return ret


def getMarketInfo(payload):
    response_text = get_response("https://api.hadax.com/market/history/kline", payload)
    dic = json.loads(response_text)['data']
    print(dic[0])
    df = pd.DataFrame(dic)
    df['id'] = pd.to_datetime(list(df['id']), unit='s', utc=True).tz_convert('Asia/Shanghai').strftime(
        "%Y-%m-%d %H:%M:%S")
    df['diff'] = df['close'] - df['open']
    return df

def main():
    df = getMarketInfo({'period': "1day", 'size': 50, 'symbol': "btcusdt"})
    # serverchan("BTC消息", df.head())
    con = df[df['diff'] < 0].index[1] - df[df['diff'] > 0].index[1]
    msg = "BTC当前价格{:,}，今日涨跌额：{:+.2f}，连续涨{}日.\n".format(df.at[0, 'close'], df.at[0, 'diff'], con)
    msg += "当前处于拐点，位于最{}点.".format("低" if con > 0 else "高") if abs(con) == 1 else ""

    df = getMarketInfo({'period': "15min", 'size': 4 * 24, 'symbol': "btcusdt"})
    possible = df[df['diff'] > 0]['amount'].sum() / df['amount'].sum()
    msg += "涨跌可能性：{:.2%}.\n".format(possible)
    if (possible - 0.5) * (con) < 0:
        msg += "建议{}\n".format("买入" if (possible - 0.5)>con else "卖出")
    #serverchan("BTC消息", msg)
    flag = ((possible - 0.5) * (con) < 0) or abs(con) == 1 # 当前涨跌与预测不一致 或 位于拐点
    if flag:
        serverchan("BTC消息",msg)
    return msg


def handler(environ, start_response):
    context = environ['fc.context']
    request_uri = environ['fc.request_uri']
    for k, v in environ.items():
      if k.startswith('HTTP_'):
        # process custom request headers
        pass
    # do something here
    status = '200 OK'
    response_headers = [('Content-type', 'text/plain')]
    start_response(status, response_headers)
    return [main()]