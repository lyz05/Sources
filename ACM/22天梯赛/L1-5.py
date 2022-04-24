#3 6 5 4 1 4
#6 5 6 6 6 6
#5 4 4 5 5 5
#4 3 3 3 4 3

a = list(map(int,input().split()))
dic = [{},{},{},{},{},{}]
n = int(input())
for i in range(6):
    dic[i][a[i]] = 1
for k in range(n):
    ans = []
    for i in range(6):
        for j in range(6,0,-1):
            if dic[i].get(j) is None:
                dic[i][j] = 1
                ans.append(j)
                break
print(' '.join(map(str,ans)))