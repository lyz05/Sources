class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def __init__(self) -> None:
        self.l = []

    def EntryNodeOfLoop(self, pHead):
        while pHead:
            if pHead in self.l:
                return pHead
            self.l.append(pHead)
            pHead = pHead.next
        return None


l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l3
print(Solution().EntryNodeOfLoop(l1))
