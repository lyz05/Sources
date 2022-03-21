class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # write code here
        if not head:
            return head
        node_list = []
        temp = head
        step = 0
        while temp:
            node_list.append(temp)
            step += 1
            if step % k == 0:
                node_list[step-k:step] = reversed(node_list[step-k:step])
            temp = temp.next

        for i in range(1, len(node_list)):
            node_list[i-1].next = node_list[i]
        return node_list[0]
