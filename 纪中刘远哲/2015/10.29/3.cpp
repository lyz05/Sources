#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100000+5;
struct point
{
	int maxx[2],id[2],up;
} a[N];

struct edge
{
	int y,w,next;
} h[2*N];

int n,tot;
int e[N];
bool vis[N];

void add(int u,int v,int w)
{
	tot ++;
	h[tot].y = v;
	h[tot].w = w;
	h[tot].next = e[u];
	e[u] = tot;
}

void dfs(int x)
{
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y;
		if (!vis[y]) 
		{
			vis[y] = 1;
			dfs(y);
			int tmp = a[y].maxx[0]+h[i].w;
			if (a[x].maxx[0]!=0)
			{
				if (tmp>a[x].maxx[1]) 
					a[x].maxx[1] = tmp,a[x].id[1] = y;
				if (a[x].maxx[0]<a[x].maxx[1]) 
					swap(a[x].maxx[0],a[x].maxx[1]),
					swap(a[x].id[0],a[x].id[1]);
			} else a[x].maxx[0] = tmp,a[x].id[0] = y;
		}
	}
}

void dfs1(int x)
{
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y;
		if (!vis[y]) 
		{
			vis[y] = 1;
			int tmp = (y==a[x].id[0])?a[x].maxx[1]:a[x].maxx[0];
			(tmp += h[i].w);
			a[y].up = max(tmp,a[x].up+h[i].w);
			dfs1(y);
		}
	}
}

int main()
{
	freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<n;i ++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	memset(vis,0,sizeof vis);
	vis[1] = 1;
	dfs(1);
	memset(vis,0,sizeof vis);
	vis[1] = 1;
	dfs1(1);
	for (int i=1;i<=n;i ++)
	{
		int tmp1 = a[i].maxx[0]+a[i].maxx[1],
		    tmp2 = a[i].maxx[0]+a[i].up;
		printf("%d\n",max(tmp1,tmp2));
	}

	return 0;
}
