class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    def removeNthFromEnd(self , head: ListNode, n: int) -> ListNode:
        # write code here
        phead = ListNode(None)
        phead.next = head
        pre, cur = phead,phead
        for i in range(n):
            cur = cur.next
        while cur.next:
            cur = cur.next
            pre = pre.next
        pre.next = pre.next.next
        return phead.next

l = ListNode(1)
print(Solution().removeNthFromEnd(l,1).next)
