import datetime

datetime.MAXYEAR = 1000000
print(datetime.MAXYEAR)
while True:
    try:
        s = input()
        date = datetime.datetime.strptime(s, '%Y %m %d')
        front_date = datetime.datetime.strptime('2000 01 01', '%Y %m %d')
        delta = date-front_date
        days = delta.days
        print(days)
        week = days//4+1
        day = days%4+1
        print('{} {}'.format(week,day))
    except EOFError:
        break