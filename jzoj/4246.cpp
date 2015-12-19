#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 1005 , M = 3005;
struct node
{
	int y,val,next;
} h[3*M];
int ans[N];
int n,m,tot;
int e[4][N],d[N],f[N],g[N];
bool vis[N];

void add(int x,int y,int z,int kind)
{
	tot ++;
	h[tot].y = y;
	h[tot].val = z;
	h[tot].next = e[kind][x];
	e[kind][x] = tot;
}

void spfa(int s,int kind)
{
	queue <int> q;
	memset(d,60,sizeof(d));
	d[s] = 0;
	memset(vis,0,sizeof(vis));

	q.push(s);
	vis[s] = 1;
	while (!q.empty())
	{
		int x = q.front();q.pop();vis[x]=0;
		for (int i=e[kind][x];i;i=h[i].next)
		{
			int y = h[i].y;
			if (d[x]+h[i].val<d[y])
			{
				d[y] = d[x]+h[i].val;
				if (!vis[y])
				{
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}

}

void make(int x)
{
	for (int i=e[3][x];i;i = h[i].next)
	{
		int y = h[i].y,val = h[i].val;
		if (d[x]+val == d[y])
		{
			add(x,y,val,1);
			add(y,x,val,2);
		}
	}
}

int getg(int x)
{
	if (g[x]==0)
	{
		for (int i=e[1][x];i;i = h[i].next)
		{
			int y = h[i].y;
			g[x] += getg(y);
		}
		if (d[x]%2==1) g[x] ++;
	}
	return g[x];
}

int getf(int x)
{
	if (f[x]==0)
		for (int i=e[2][x];i;i = h[i].next)
		{
			int y = h[i].y;
			f[x] += getf(y);
		}
	return f[x];
}

void work()
{
	for (int i=1;i<=n;i ++)
	{
		ans[i] += f[i]*g[i];
	}
}

int main()
{
	freopen("4246.in","r",stdin);
	//freopen("3.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,3);
		add(y,x,z,3);
	}

	for (int i=1;i<=n;i ++)
	{
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		memset(e[1],0,sizeof e[1]);
		memset(e[2],0,sizeof e[2]);
		tot = 2*m;
		f[i] = 1;
		spfa(i,3);
		for (int j=1;j<=n;j ++) make(j);
		getg(i);
		for (int j=1;j<=n;j ++)
			if (!e[1][j]) getf(j);
		work();
	}
	for (int i=1;i<=n;i ++) printf("%d\n",ans[i]);
	return 0;
}
