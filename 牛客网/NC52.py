#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param s string字符串 
# @return bool布尔型
#
class Solution:
    def isValid(self , s: str) -> bool:
        dic = {'[':']','{':'}','(':')'}
        st = []
        for i in s:
            if i in '({[':
                st.append(i)
            elif i in ')}]' and (len(st)==0 or not dic[st.pop()]==i):
                return False
        return len(st)==0
        # write code here

print(Solution().isValid("["))
