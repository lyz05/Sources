#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 100000+5,M = 200000+5;
int n,m,e[N],vis[N],x[2*M+N],y[2*M+N],z[2*M+N],fa[N];
long long ans,d[N];
int tot,etot;
struct node
{int y,next,w;} h[2*M+N];

int gf(int x)
{
	if (fa[x]!=x) fa[x] = gf(fa[x]);
	return fa[x];
}

void add(int x,int y,int z)
{
	++ etot;
	h[etot].y = y;
	h[etot].w = z;
	h[etot].next = e[x];
	e[x] = etot;
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
			if (d[x]+h[i].w<d[y])
			{
				d[y] = d[x] + h[i].w;
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
	freopen("4261.in","r",stdin);
	//freopen("mission.out","w",stdout);
	
	int flag = 0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) 
	{
		int col;
		scanf("%d",&col);
		if (col) 
			add(0,i,0) , flag = 1;
	}
	if (!flag)
	{
		puts("impossible");
		return 0;
	}
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	spfa(0);

	tot = 0;
	for (int i=1;i<=n;i ++)
	{
		fa[i] = i;
		for (int j=e[i];j;j=h[j].next)
		if (d[i] + h[j].w == d[h[j].y])
		{
			x[++ tot] = i;
			y[tot] = h[j].y;
			z[tot] = h[j].w;
		}
	}

	for (int i=1;i<=tot;i ++)
		if (gf(x[i])!=gf(y[i]))
		{
			ans += z[i];
			fa[gf(x[i])] = gf(y[i]);
		}
	printf("%lld\n",ans);
	return 0;
}
