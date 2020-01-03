#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 100000+5,M = 500000+5;
struct node
{int y,next;} h[2*M],h2[2*M];

int e[N],e2[N],vis[N],p[N],d[N],v[N];
int ans,n,m;

void add(int x,int y)
{
	static int tot;
	++ tot;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
	
	h2[tot].y = x;
	h2[tot].next = e2[y];
	e2[y] = tot;
}

void dfs(int x)
{
	if (p[x]) return;
	p[x] = 1;
	for (int i=e2[x];i;i = h2[i].next) 
		dfs(h2[i].y);
}

void spfa(int u)
{
	static queue <int> q;
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[u] = v[u];
	q.push(u);
	vis[u] = 1;
	while (!q.empty())
	{
		int x = q.front();q.pop();vis[x] = 0;
		for (int i=e[x];i;i=h[i].next)
		{
			int y = h[i].y;
			if (d[x]<d[y] || v[y]<d[y])
			{
				d[y] = min(d[y],d[x]);
				d[y] = min(d[y],v[y]);
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
	freopen("1754.in","r",stdin);
	//freopen("1754.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) scanf("%d",&v[i]);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (z==1) add(x,y); else add(x,y),add(y,x);
	}
	dfs(n);
	spfa(1);
	for (int i=1;i<=n;i ++) if (p[i]) ans = max(ans,v[i]-d[i]);
	printf("%d\n",ans);
	return 0;
}
