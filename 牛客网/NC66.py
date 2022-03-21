from cmath import phase


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

#
# 
# @param pHead1 ListNode类 
# @param pHead2 ListNode类 
# @return ListNode类
#
class Solution:
    def FindFirstCommonNode(self , pHead1 , pHead2 ):
        dic = {}
        while pHead1:
            dic[pHead1] = True
            pHead1 = pHead1.next
        while pHead2:
            if dic.get(pHead2,False):
                return pHead2
            dic[pHead2] = True
            pHead2 = pHead2.next
        return None
        # write code here

Solution().FindFirstCommonNode()