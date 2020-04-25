#include <iostream>
#include <cstdio>
using namespace std;

const int kind = 26; //字母种类
int tot;

struct Treenode //树的结点结构
{
    int count;            //这个附加变量在本题中记录遍历到该结点形成的字符串出现的次数，在不同题中可记录不同的内容。
    Treenode *next[kind]; //指向儿子结点
    Treenode()            //每个结点的初始化
    {
        count = 0;
        for (int i = 0; i < kind; i++)
            next[i] = NULL;
    }
};

void insert(Treenode *&root, char *word) //向以root为根结点的树中插入串word
{
    Treenode *location = root;
    int i = 0, branch = 0;

    if (location == NULL)
    {
        location = new Treenode();
        root = location;
    }

    while (word[i])
    {
        branch = word[i] - 'a';
        if (location->next[branch] == NULL)
            //    location->next[branch]->count++; //如果该字符存在，串数量加1
            //else
            location->next[branch] = new Treenode(); //如果不存在，建新结点
        i++;
        if (word[i] == '\0')
            location->next[branch]->count++;
        location = location->next[branch];
    }
}

void dfs(Treenode *root, char *word, int i)
{
    Treenode *location = root;
    if (location == NULL)
        return;

    for (int branch = 0; branch < 26; branch++)
    {
        if (location->next[branch] == NULL)
            continue;
        word[i] = branch + 'a';
        word[i + 1] = '\0';
        if (location->next[branch]->count && tot<50){
            tot ++;
            cout << word << endl;
        }
        dfs(location->next[branch], word, i + 1);
    }
}

int search(Treenode *root, char *word) //查找，与插入类似
{
    Treenode *location = root;
    int i = 0, branch = 0, ans;

    if (location == NULL)
        return -1;

    while (word[i])
    {
        branch = word[i] - 'a';
        if (!location->next[branch])
            return -1;
        i++;
        location = location->next[branch];
        ans = location->count;
    }
    dfs(location, word, i);

    return ans;
}
int n, T;
char word[125];
char ask[125];
int main()
{
    freopen("S.in", "r", stdin);
    //freopen(".out","w",stdout);

    Treenode *root = NULL;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(word);
        insert(root, word);
    }
    cin >> T;
    getchar();
    while (T--)
    {
        gets(ask);
        cout << ask << endl;
        tot = 1;
        if (search(root, ask) == -1)
        {
            insert(root, ask);
        }
    }

    return 0;
}