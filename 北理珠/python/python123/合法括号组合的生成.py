list = []
n = 0
def dfs(dep,now,str):
    if (dep>2*n):
        if (now==0):
            list.append(str)
        return
    else:
        dfs(dep+1,now+1,str+'(')
        if (now>0):
            dfs(dep+1,now-1,str+')')

n = eval(input())
dfs(1,0,'')
print(list)