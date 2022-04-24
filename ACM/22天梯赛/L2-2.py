def show(num):
    return "{}:{}:{}".format(str(num//3600).zfill(2),str(num%3600//60).zfill(2),str(num%60).zfill(2))
n = int(input())
a = []
for i in range(60*60*24):
    a.append(0)
for i in range(n):
    st,en = input().split(' - ')
    st = list(map(int,st.split(':')))
    en = list(map(int,en.split(':')))
    st = st[0]*3600+st[1]*60+st[2]
    en = en[0]*3600+en[1]*60+en[2]
    # print(st,en)
    a[st] += 1
    a[en] += -1
for i in range(1,60*60*24):
    a[i] = a[i]+a[i-1]

st = 0
en = -1
for i in range(1,60*60*24):
    if (a[i-1]>0 and a[i]==0):
        st = i
    if (a[i-1]==0 and a[i]>0):
        en = i
    if (st!=-1 and en!=-1):
        print("{} - {}".format(show(st),show(en)))
        st = -1
        en = -1
if (st!=-1):
    en = 60*60*24-1
    print("{} - {}".format(show(st),show(en)))