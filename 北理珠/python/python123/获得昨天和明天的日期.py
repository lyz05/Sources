import datetime
import sys


def next_day(date_str):
    date = datetime.datetime.strptime(date_str, '%Y-%m-%d')
    date = date + datetime.timedelta(days=1)
    return date.strftime("%Y-%m-%d")


def prev_day(date_str):
    date = datetime.datetime.strptime(date_str, '%Y-%m-%d')
    date = date - datetime.timedelta(days=1)
    return date.strftime("%Y-%m-%d")


while True:
    line = sys.stdin.readline()
    line = line.strip()
    if line == '':
        break
    print('前一天:', prev_day(line))
    print('后一天:', next_day(line))
