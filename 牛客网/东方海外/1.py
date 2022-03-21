# -*- coding:utf-8 -*-
class Solution:
    # 约瑟夫环
    def LastRemaining_Solution(self, n, m):
        # write code here
        l = []
        for i in range(n):
            l.append(i)
        index = 0
        while len(l)>1:
            index = (index+m-1)%len(l)
            #print(l[index])
            l.pop(index)
            #index = (index+1)%len(l)
            #print(l)
        return l[0]

print(Solution().LastRemaining_Solution(5,3))
print(Solution().LastRemaining_Solution(2,3))
print(Solution().LastRemaining_Solution(10,17))