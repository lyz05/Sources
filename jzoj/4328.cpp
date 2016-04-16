#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 300000+5;
int n,m;
int e[N],next[2*N],to[2*N],d[2*N];
int E[N],Next[2*N],To[2*N];
int dis[N],fa[N],h[N],vis[N],a[N],s[N];
struct node
{
	int u,v,lca,ans;
} Q[N];


bool cmp(node A,node B)
{
	return A.ans<B.ans;
}
void add(int x,int y,int z)
{
	static int tot;
	to[++ tot] = y;
	d[tot] = z;
	next[tot] = e[x];
	e[x] = tot;
}
void Add(int x,int y)
{
	static int tot;
	To[++ tot] = y;
	Next[tot] = E[x];
	E[x] = tot;
}

int gf(int x)
{
	if (x!=h[x]) h[x] = gf(h[x]);
	return h[x];
}
void dfs(int x)
{
	h[x] = x;
	vis[x] = 1;
	for (int i=e[x];i;i = next[i])
	{
		int y = to[i];
		if (y==fa[x]) continue;
		fa[y] = x;
		dis[y] = dis[x] + d[i];
		dfs(y);
		h[y] = x;
	}
	for (int i=E[x];i;i=Next[i])
	{
		int y;
		if (x==Q[To[i]].u) y = Q[To[i]].v;
		else y = Q[To[i]].u;
		Q[To[i]].lca = gf(y);
		if (vis[y])
			Q[To[i]].ans = dis[x]+dis[y]-dis[gf(y)]*2;
	}
}
void bfs(int x)
{
	int l = 0,r = 1;
	a[1] = x;
	while (l<r)
	{
		x = a[++ l];
		for (int i=e[x];i;i=next[i])
		{
			int y = to[i];
			if (y==fa[x]) continue;
			a[++ r] = y;
		}
	}
}

bool judge(int Lim)
{
	memset(s,0,sizeof s);
	int cur = 0;
	for (int i=m;i;i --)
		if (Q[i].ans<=Lim) break;
		else
		{
			s[Q[i].u] ++,s[Q[i].v] ++,s[Q[i].lca] -=2;
			cur ++;
		}
	int ans = 0;
	for (int i=n;i;i --)
	{
		int x = a[i];
		if (s[x]==cur)
			ans = max(ans,dis[x]-dis[fa[x]]);
		s[fa[x]] += s[x];
	}
	return Q[m].ans - ans <= Lim;
}

int main()
{
	freopen("transport.in","r",stdin);
	//freopen("transport.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	for (int i=1;i<=m;i ++)
	{
		scanf("%d%d",&Q[i].u,&Q[i].v);
		Add(Q[i].u,i);Add(Q[i].v,i);
	}
	dfs(1);
	sort(Q+1,Q+1+m,cmp);
	bfs(1);
	int l = 0,r = Q[m].ans,ans = 0;
	while (l<r)
	{
		int mid = (l+r)>>1;
		if (judge(mid))
		{
			ans = mid;
			r = mid;
		} else l = mid+1;
	}
	printf("%d\n",ans);

	return 0;
}
