from asyncore import poll3


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def print(self):
        print(self.val)
        if self.next:
            self.next.print()


class Solution:
    def Merge(self, pHead1: ListNode, pHead2: ListNode) -> ListNode:
        if pHead1 is None or pHead2 is None:
            return pHead1 or pHead2
        elif pHead1.val < pHead2.val:
            pHead1.next = self.Merge(pHead1.next,pHead2)
            return pHead1
        else:
            pHead2.next = self.Merge(pHead1,pHead2.next)
            return pHead2


A = ListNode(1)
A.next = ListNode(3)
A.next.next = ListNode(5)
B = None
S = Solution()
A.print()
C = S.Merge(A, B)
C.print()
