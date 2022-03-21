#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param array int整型一维数组 
# @return int整型
#
class Solution:
    def FindGreatestSumOfSubArray(self , array: list[int]) -> int:
        # write code here
        f = [0]*len(array)
        ans = f[0] = array[0]
        for i in range(1,len(array)):
            f[i] = max(f[i-1]+array[i],array[i])
            ans = max(ans,f[i])
        return ans

print(Solution().FindGreatestSumOfSubArray([1,-2,3,10,-4,7,2,-5]))
print(Solution().FindGreatestSumOfSubArray([2]))
print(Solution().FindGreatestSumOfSubArray([-10]))