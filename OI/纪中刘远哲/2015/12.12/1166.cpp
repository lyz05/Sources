#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 10005;
struct node
{
	int y,w,next;
} h[2*N];
int len,ans,n,m;
int e[N],f[N],a[N];
LL dis[N];
bool vis[N];

void add(int x,int y,int w)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].w = w;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x)
{
	vis[x] = 1;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		if (!vis[y])
		{
			dis[y] = dis[x] + h[i].w;
			dfs(y);
		}
	}
}

int find(int x)
{
	if (x==f[x]) return x;
	return f[x] = find(f[x]);
}

void LCA(int x)
{
	vis[x] = 1;
	f[x] = x;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		if (!vis[y]) 
		{
			LCA(h[i].y);
			f[y] = x;
		}
	}
	for (int i=1;i<=a[0];i ++)
	{
		int y = a[i];
		LL lenn = dis[x]+dis[y]-2*dis[find(y)];
		if (lenn<=len) ans ++;
	}
	a[++ a[0]] = x;
}

int main()
{
	freopen("1166.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&len);
	for (int i=1;i<n;i ++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	memset(vis,0,sizeof vis);
	dfs(1);
	memset(vis,0,sizeof vis);
	LCA(1);
	printf("%d\n",ans);

	return 0;
}
