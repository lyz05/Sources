
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param s string字符串  
# @return int整型



class Solution:
    def MinOperations(self, s) :
        # write code here
        i = 0
        j = 1
        ans1 = 0
        ans2 = 0
        for ch in s:
            now = (1 if ch=='A' else 0)
            if now!=i:
                ans1 += 1
            else:
                ans2 += 1
            i ^= 1
            j ^= 1
        return min(ans1,ans2)

S = Solution().MinOperations("ABAA")
print(S)
S = Solution().MinOperations("AB")
print(S)