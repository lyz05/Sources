
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param nums1 int整型 一维数组 一维整型数组
# @param m int整型  数组nums1的长度
# @param nums2 int整型 一维数组 一维整型数组
# @param n int整型  数组nums2的长度
# @return int整型一维数组
#
class Solution:
    def MergeAarryNum(self, nums1, m, nums2, n) :
        nums = nums1[:m-n]+nums2[:n]
        nums = sorted(nums)
        return nums
        
S = Solution()
print(S.MergeAarryNum([1,2,3,0,0,0],6,[4,5,6],3))
print(S.MergeAarryNum([4,5,6,0],4,[1],1))