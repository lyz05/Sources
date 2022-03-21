class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    def __init__(self) -> None:
        self.l = []

    def hasCycle(self , head: ListNode) -> bool:
        while head:
            if head in self.l:
                return True
            self.l.append(head)
            head = head.next
        return False

l1 = ListNode(3)
l2 = ListNode(2)
l3 = ListNode(0)
l4 = ListNode(-4)
l1.next=l2
l2.next=l3
l3.next=l4
l4.next=l2
print(Solution().hasCycle(l1))
