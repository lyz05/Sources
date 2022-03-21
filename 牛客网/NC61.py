#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param numbers int整型一维数组 
# @param target int整型 
# @return int整型一维数组
#
class Solution:
    def twoSum(self , numbers: list[int], target: int) -> list[int]:
        # write code here
        dic = {}
        for i in range(len(numbers)):
            dic[numbers[i]] = i
        for i in range(len(numbers)):
            newtarget = target - numbers[i]
            if dic.get(newtarget,None):
                return [i+1,dic[newtarget]+1]

print(Solution().twoSum([5,75,25],100))
