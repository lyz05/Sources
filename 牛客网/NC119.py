#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param input int整型一维数组 
# @param k int整型 
# @return int整型一维数组
#
class Solution:
    def GetLeastNumbers_Solution(self , input: list[int], k: int) -> list[int]:
        # write code here
        input = sorted(input)
        return input[:k]
        

S = Solution()
res = S.GetLeastNumbers_Solution([4,5,1,6,2,7,3,8],4)
print(res)