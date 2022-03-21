#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param target int整型 
# @param array int整型二维数组 
# @return bool布尔型
#
class Solution:
    def Find(self , target: int, array: list[list[int]]) -> bool:
        pass
        m = len(array)
        n = len(array[0])
        i,j = m-1,0
        while i>=0 and j<n:
            now = array[i][j]
            print(now)
            if target<now:
                i -= 1
            elif target>now:
                j += 1
            else:
                return True
        return False
        # write code here

print(Solution().Find(7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]))
print(Solution().Find(1,[[2]]))
print(Solution().Find(3,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]))
