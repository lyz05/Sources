from tkinter.tix import Tree


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param pRoot TreeNode类 
# @return int整型二维数组
#
class Solution:
    def maxDepth(self , root: TreeNode) -> int:
        # write code here
        def pre(root,deep):
            if not root:
                return deep
            return max(pre(root.left,deep+1),pre(root.right,deep+1))
        return pre(root,0)

t = TreeNode(1)
t.left = TreeNode(2)
t.right = TreeNode(3)
t.right.left = TreeNode(4)
t.right.right = TreeNode(5)
print(Solution().maxDepth(t))