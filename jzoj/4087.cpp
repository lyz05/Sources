#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 505,M = 100005;
const LL INF = 1e15;
struct Edge
{
	int y,w,next;
} h[2*M],H[2*M];
int e[N],E[2*N],final[2*N],gap[2*N];
int n,m,s,t;
LL ans,d[N*2],f[M*2];
bool vis[N];

void add(int x,int y,int z)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].w = z;
	h[tot].next = e[x];
	e[x] = tot;
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

void Add(int x,int y,LL z)
{
	static int tot;
	H[++ tot].y = y;
	H[tot].next = E[x];
	f[tot] = z;
	E[x] = tot;
}

void build()
{
	for (int i=1;i<n;i ++)
	{
		for (int j=e[i];j;j=h[j].next)
		{
			if (d[i]+h[j].w == d[h[j].y])
			{
				if (i==1)
					Add(1,h[j].y,INF),Add(h[j].y,1,0);
				else Add(i+n,h[j].y,INF),Add(h[j].y,i+n,0);
			}
		}
	}
	for (int i=1;i<=n;i ++)
	{
		LL x;
		scanf("%lld",&x);
		if (i==1 || i==n) continue;
		Add(i,i+n,x),Add(i+n,i,0);
	}
}

LL dfs(int now,LL limit)
{
	if (now==t) 
		return limit;
	LL ret = 0;
	for (int i=E[now];i;i=H[i].next) if (f[i]) // 还能流流量
	{
		E[now] = i;
		int j = H[i].y;
		if (d[j]+1!=d[now]) continue;
		LL tmp = dfs(j,min(limit-ret,f[i]));
		f[i] -= tmp;
		ret += tmp;
		if (i & 1) f[i+1] += tmp;else f[i-1] += tmp;
		if (ret==limit) return ret;
	}
	E[now] = final[now];
	gap[d[now]] --;
	if (!gap[d[now]]) d[s] = 2*n-2;
	gap[++ d[now]] ++;
	return ret;
}

void sap()
{
	s = 1,t = n;
	memset(d,0,sizeof d);
	gap[0] = n*2-2;
	for (int i=1;i<=2*n;i ++) final[i] = E[i];
	while (d[s]<2*n-2) 
		ans += dfs(s,INF);
}

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	spfa(1);
	build();
	sap();
	printf("%lld\n",ans);
	return 0;
}

