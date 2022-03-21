#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param buttons int整型一维数组 
# @return long长整型
#
class Solution:
    def findMaxButtons(self , buttons ):
        # write code here
        ans = 0
        for i in range(len(buttons)):   
            ans += (buttons[i]-1)*(i+1)
        ans += len(buttons)
        return ans

S = Solution()
print(S.findMaxButtons([1,1,4,5,1,4]))