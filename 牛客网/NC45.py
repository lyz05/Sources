
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param root TreeNode类 the root of binary tree
# @return int整型二维数组
#


class Solution:

    def threeOrders(self, root: TreeNode) -> list[list[int]]:
        # write code here
        res1 = []
        res2 = []
        res3 = []

        def pre(root):
            if not root:
                return
            res1.append(root.val)
            pre(root.left)
            pre(root.right)

        def middle(root):
            if not root:
                return
            middle(root.left)
            res2.append(root.val)
            middle(root.right)

        def last(root):
            if not root:
                return
            last(root.left)
            last(root.right)
            res3.append(root.val)
        pre(root)
        middle(root)
        last(root)
        return [res1,res2,res3]


t = TreeNode(1)
t.left = TreeNode(2)
t.right = TreeNode(3)
S = Solution()
print(S.threeOrders(t))
