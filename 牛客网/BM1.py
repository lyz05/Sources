from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def print(self):
        print(self.val)
        if self.next:
            self.next.print()

class Solution:
    def ReverseList(self , head: ListNode) -> ListNode:
        prev = None
        cur = head
        while cur:
            tmp = cur.next
            cur.next = prev
            prev = cur
            cur = tmp
        return prev
    
        

s = Solution()
l = ListNode(1)
l.next = ListNode(2)
l.next.next = ListNode(3)
l.print()
print()
l = s.ReverseList(l)
l.print()