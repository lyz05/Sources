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
    def hasPathSum(self , root: TreeNode, sum: int) -> bool:
        # write code here
        if not root:
            return False
        res = False
        def pre(root,length):
            length += root.val
            if root.left:
                pre(root.left,length)
            if root.right:
                pre(root.right,length)
            if not root.left and not root.right:
                print(length)
                if (sum==length):
                    nonlocal res
                    res = True
        pre(root,0)
        return res

t = TreeNode(1)
t.left = TreeNode(2)
t.right = TreeNode(3)
t.right.left = TreeNode(4)
t.right.right = TreeNode(5)
print(Solution().hasPathSum(t,22))