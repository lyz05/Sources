#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

const int N = 1e6+5;
char s[N];
int ans[N];
int n,q,tmp;

const int kind = 26;
struct node
{
	int cnt;
	node *next[kind];
	node() {for (int i=0;i<kind;i ++) next[i]=NULL;}
};

void insert(node *&root,char word[])
{
	node *now = root;
	if (now==NULL) 
	{
		now = new node();root = now;
	}
	int len = strlen(word);
	for (int i=0;i<len;i ++)
	{
		int id = word[i]-'a';
		if (now->next[id]==NULL) 
		{
			now->next[id]=new node();
			tmp = (tmp==-1)?i:tmp;
		}
		now = now->next[id];
	}
	tmp = (tmp==-1)?len:tmp;
}

int main()
{
	freopen("3126.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&q);
	node *root = NULL;
	for (int i=1;i<=n;i ++)
	{
		tmp = -1;
		scanf("%s",s);
		insert(root,s);
		ans[i] = max(ans[i-1],tmp);
	}
	while (q --)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}
