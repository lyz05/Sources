
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param s string字符串  字符串数组
# @param n int整型  需要翻转的字符个数
# @return string字符串
#
from re import L


class Solution:
    def longestPalindrome(self, s) :
        # write code here
        def judge(s):
            return s==s[::-1]
        for length in range(len(s),-1,-1):
            for i in range(0,len(s)-length):
                if judge(s[i:i+length+1]):
                    return s[i:i+length+1]
        return ""
            


S = Solution()
ans = S.longestPalindrome("babad")
print(ans)
ans = S.longestPalindrome("abcbacdcabba")
print(ans)
ans = S.longestPalindrome("a")
print(ans)