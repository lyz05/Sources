year, num = input().split()
x = 0
while(True):
    year = year.zfill(4)
    dic = {}
    for ch in year:
        dic[ch] = 1
    #print(year,len(dic))
    if len(dic) == int(num):
        print(x, year)
        exit(0)
    x += 1
    year = str(int(year)+1)
