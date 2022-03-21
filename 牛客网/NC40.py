from xml.dom.minicompat import NodeList


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    def print(self):
        now = self
        while now:
            print(now.val)
            now = now.next

#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head1 ListNode类 
# @param head2 ListNode类 
# @return ListNode类
#
class Solution:
    def addInList(self , head1: ListNode, head2: ListNode) -> ListNode:
        l1 = []
        l2 = []
        while head1:
            l1.append(head1.val)
            head1 = head1.next
        while head2:
            l2.append(head2.val)
            head2 = head2.next
        
        jw = 0
        prev = None
        while l1 or l2:
            num1 = int(l1.pop()) if l1 else 0
            num2 = int(l2.pop()) if l2 else 0
            now = ListNode((num1+num2+jw)%10)
            jw = (num1+num2+jw)//10
            now.next = prev
            prev = now
        if jw>0:
            now = ListNode(jw)
            now.next = prev
            prev = now
        return prev
        pass
        # write code here

head1 = ListNode(9)
head1.next = ListNode(3)
head1.next.next = ListNode(7)
head2 = ListNode(6)
head2.next = ListNode(3)
Solution().addInList(head1,head2).print()