
class Solution:
    def merge(self , A, m, B, n):
        # write code here
        for i in range(m,m+n):
            A[i] = B[i-m]
        A.sort()
        pass

Solution().merge([4,5,6],[1,2,3],3,3)