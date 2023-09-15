#tuisong: 
# now: 25 5
#hezi:  
def printf(now):
    now = map(str,now)
    print(" ".join(now))

n, m, k = map(int, input().split())
tuisong = list(map(int,input().split()))
hezi = []
now = []
i = 0
while(i<n):
    item = tuisong[i]

    if len(now)==0:
        if len(hezi)==0:
            now.append(item)
        else:
            i -=1
            now.append(hezi.pop())
    else:
        #(3)
        if len(now)==k:
            printf(now)
            now = []
            continue
        if len(hezi)>0 and now[-1]>=hezi[-1]:
            i -=1
            now.append(hezi.pop())
        elif now[-1]>=item:
            now.append(item)
        else:
            #(1)
            if len(hezi)==m:
                printf(now)
                now = []
                i -= 1
            else:
                hezi.append(item)
    i+=1
#(2)
while (len(hezi)>0):
    if len(now)>0:
        if now[-1]>=hezi[-1]:
            now.append(hezi.pop())
        else:
            printf(now)
            now = []
    else:
        now = hezi.pop()
if len(now)>0:
    printf(now)
    now = []
