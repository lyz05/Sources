
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param s string字符串  字符串数组
# @param n int整型  需要翻转的字符个数
# @return string字符串
#
class Solution:
    def LeftShiftOne(self, s, n) :
        # write code here
        return s[n:]+s[0:n]

S = Solution()
ans = S.LeftShiftOne("shopee",2)
print(ans)