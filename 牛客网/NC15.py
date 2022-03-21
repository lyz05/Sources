class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param root TreeNode类 
# @return int整型二维数组
#
class Solution:
    def levelOrder(self , root: TreeNode) -> list[list[int]]:
        res = []
        def pre(root,deep):
            if not root:
                return
            if len(res)<=deep:
                res.append([])
            res[deep].append(root.val)
            pre(root.left,deep+1)
            pre(root.right,deep+1)
        pre(root,0)
        return res

t = TreeNode(1)
t.left = TreeNode(2)
S = Solution()
print(S.levelOrder(t))
