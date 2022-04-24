
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param n int整型  
# @return int整型
#
ans = 0
class Solution:
    def buildHouses(self, n):
        if n==0:
            return 0
        global ans
        ans = 0
        flag = [False]*(n+1)
        a = [0]*(n+1)
        def check():
            global ans
            for i in range(1,n+1):
                for j in range(i+1,n+1):
                    dx = abs(j-i)
                    dy = abs(a[i]-a[j])
                    if dx==dy:
                        ans -= 1
                        return

        def dfs(x):
            if (x==n+1):
                check()
                global ans
                ans += 1
                return
            for y in range(1,n+1):
                if not flag[y]:
                    flag[y] = True
                    a[x] = y
                    dfs(x+1)
                    flag[y] = False
            
        dfs(1)
        return ans
        # write code here
S = Solution()
for i in range(15):
    print(S.buildHouses(i))
