#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1005;
struct node
{
	int y,next;
} h[2*N];
int dfn[N],low[N],stack[N];
int tot,n,ans,Index,top,fa[N],e[N];
bool instack[N];

void add(int x,int y)
{
	h[++ tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

void tarjan(int x)
{
	dfn[x] = low[x] = ++ Index;
	instack[x] = 1;
	stack[++ top] = x;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		//if (col[y]) continue;
		if (instack[y]) low[x] = min(low[x],dfn[y]);
		else {tarjan(y);low[x]=min(low[x],low[y]);}
	}
	if (dfn[x]==low[x])
	{
		int y,num = 0;
		do
		{
			y = stack[top --];
			instack[y] = 0;
			num ++;
		} while (y!=x);
		ans = max(ans,num);
	}
}

int dfs(int x,int dep)
{
	int ret = dep;
	for (int i=e[x];i;i = h[i].next) 
		if (h[i].y!=fa[x]) ret = max(ret,dfs(h[i].y,dep+1));
	return ret;
}

int main()
{
	freopen("13.in","r",stdin);
	//freopen("3.out","w",stdout);

	int T;
	scanf("%d",&T);
	for (int k=1;k<=T;k ++)
	{
		tot = 0;ans = 0;
	       	memset(e,0,sizeof e);
		memset(dfn,0,sizeof dfn);

		scanf("%d",&n);
		for (int i=1;i<=n;i ++)
		{
			scanf("%d",&fa[i]);
			add(fa[i],i);
		}
		for (int i=1;i<=n;i ++) 
			if (!dfn[i]) tarjan(i);
		
		int ans1 = 0;
		for (int i=1;i<=n; i++) 
			if (fa[fa[i]]==i) ans1 += dfs(i,1)+dfs(fa[i],1);
		ans = max(ans,ans1/2);
		printf("Case #%d: ",k);
		printf("%d\n",ans);
	}

	return 0;
}
