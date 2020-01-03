#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5+5,oo = 1e9+7;
int e[N];
int n,ans = oo,tot;
bool vis[N];

struct point
{
	int size,fa;
} a[N];
struct node
{
	int y,next;
} h[2*N];

void add(int x,int y)
{
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x,int fa)
{
	a[x].fa = fa;
	a[x].size = 1;
	vis[x] = true;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		if (!vis[y])
		{
			dfs(y,x);
			a[x].size += a[y].size;
		}
	}
}

int calc(int x)
{
	int ret = 0;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		if (y!=a[x].fa) ret = max(ret,a[y].size);
	}
	ret = max(ret,a[1].size-a[x].size);
	return ret;
}

int main()
{
	freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i ++)
	{
		ans = min(ans,calc(i));
	}
	printf("%d\n",ans);
	
	return 0;
}

