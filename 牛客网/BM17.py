#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param nums int整型一维数组 
# @param target int整型 
# @return int整型
#
class Solution:
    def search(self , nums: list[int], target: int) -> int:
        dic = {}
        cnt = 0
        for i in nums:
            dic[i] = cnt
            cnt += 1
        return dic.get(target,-1)
        # write code here

S = Solution()
print(S.search([-1,0,3,4,6,10,13,14],13))
print(S.search([],3))
print(S.search([-1,0,3,4,6,10,13,14],2))
