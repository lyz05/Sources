#include <cstdio>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() {}
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    const static int N = 1e4+7;
    int tot;
    TreeNode *a[N];
    int b[N];
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回恢复后的二叉搜索树的根节点
     * @param root TreeNode类 传入二叉搜索树的根节点
     * @return TreeNode类
     */
    Solution(){
        //memset(a,0,sizeof a);
        tot = 0;
    }

    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        a[tot ++] = root;
        dfs(root->right);
    }

    TreeNode *TreeRecover(TreeNode *root)
    {
        // write code here
        TreeNode *proot = root;
        dfs(proot);
        for (int i=0;i<tot;i ++)
        {
            b[i] = a[i]->val;
            printf("%d",b[i]);
        }
        printf("\n");
        sort(b,b+tot);
        for (int i=0;i<tot;i ++)
        {
            printf("%d",b[i]);
            a[i]->val = b[i];
        }
        return root;
    }
};

int main()
{
    TreeNode t1(1), t2(2), t3(3);
    t1.left = &t2;
    t1.right = &t3;
    Solution *S = new Solution();
    S->TreeRecover(&t1);
    return 0;
}