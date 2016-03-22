#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 10000+5,M = 12000+5; 
struct node
{
	int next,y,len;
} h[2*M];
int n,m,T,tot,maxl,ans;
int e[N],d[N],dep[N],fa[N][18],Q[N],stack[N],rd[N],dis[N];
bool vis[N];

void add(int x,int y,int z)
{
	h[++ tot].y = y;
	h[tot].len = z;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x)
{
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y;
		if (!vis[y])
		{
			vis[y] = 1;
			dep[y] = dep[x] + 1;
			fa[y][0] = x;
			dis[y] = dis[x] + h[i].len;
			dfs(y);
		}
	}
}


int LCA(int x,int y)
{
	if (dep[x]>dep[y]) swap(x,y);
	for (int i=maxl;i>=0;i --) 
		if (dep[fa[y][i]]>=dep[x]) y = fa[y][i];
	if (x==y) return x;
	for (int i=maxl;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x = fa[x][i],y = fa[y][i];
	return fa[y][0];
}

void spfa(int u)
{
	static queue <int> q;
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[u] = 0;
	q.push(u);
	vis[u] = 1;
	while (!q.empty())
	{
		int x = q.front();q.pop();vis[x] = 0;
		for (int i=e[x];i;i=h[i].next)
		{
			int y = h[i].y;
			if (d[x]+h[i].len<d[y])
			{
				d[y] = d[x] + h[i].len;
				if (!vis[y])
				{
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
}


int main()
{
	freopen("3395.in","r",stdin);
	//freopen(".out","w",stdout);

	tot = 1;
	scanf("%d%d%d",&n,&m,&T);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	if (m==n-1)
	{
		memset(vis,0,sizeof vis);
		vis[1] = 1;
		dep[1] = 1;
		dfs(1);
		for (;;maxl ++) if ((1 << maxl) > m) break;
		for (int x=1;x<=n;x ++)
			for (int i=1;i<=maxl;i ++)
				fa[x][i] = fa[fa[x][i-1]][i-1];
	}
	while (T --)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (m==n-1) ans = dis[x]+dis[y]-2*dis[LCA(x,y)];
		else {spfa(x);ans = d[y];}
		printf("%d\n",ans);
		//printf("%d\n",lca(x,y));
	}

	return 0;
}
