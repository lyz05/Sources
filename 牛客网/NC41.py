#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param arr int整型一维数组 the array
# @return int整型
#
class Solution:
    def maxLength(self , arr: list[int]) -> int:
        # write code here
        l = []
        ans = 0
        for item in arr:
            while item in l:
                l.pop(0)
            l.append(item)
            ans = max(ans,len(l))
        return ans

print(Solution().maxLength([2,3,4,5]))
print(Solution().maxLength([2,2,3,4,3]))
print(Solution().maxLength([9]))
print(Solution().maxLength([1,2,3,1,2,3,2,2]))
print(Solution().maxLength([2,2,3,4,8,99,3]))

