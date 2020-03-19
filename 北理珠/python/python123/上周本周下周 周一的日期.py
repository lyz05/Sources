import sys
import datetime
import calendar


def last_monday(date_str):
    today = date_str.split("-")
    todayweekday = calendar.weekday(int(today[0]), int(today[1]), int(today[2]))
    d = datetime.datetime.strptime(date_str, "%Y-%m-%d")
    return (d + datetime.timedelta(days=-todayweekday - 7)).strftime("%Y-%m-%d")


def this_monday(date_str):
    today = date_str.split("-")
    todayweekday = calendar.weekday(int(today[0]), int(today[1]), int(today[2]))
    d = datetime.datetime.strptime(date_str, "%Y-%m-%d")
    return (d + datetime.timedelta(days=-todayweekday)).strftime("%Y-%m-%d")


def next_monday(date_str):
    today = date_str.split("-")
    todayweekday = calendar.weekday(int(today[0]), int(today[1]), int(today[2]))
    d = datetime.datetime.strptime(date_str, "%Y-%m-%d")
    return (d + datetime.timedelta(days=-todayweekday + 7)).strftime("%Y-%m-%d")


while True:
    line = sys.stdin.readline()
    line = line.strip()
    if line == '':
        break
    print('输入日期:', line)
    print('上周一:', last_monday(line))
    print('本周一:', this_monday(line))
    print('下周一:', next_monday(line))
