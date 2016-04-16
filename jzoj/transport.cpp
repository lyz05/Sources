#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 3e5 + 10;
int to[N * 2],next[N * 2],g[N],d[N * 2];
int G[N],To[N * 2],Next[N * 2];
int dep[N],fa[N],f[N],p[N],a[N],s[N];
struct qry
{
	int u,v,lca,ans;
} Q[N];
int n,m,tot,Tot,nt,ans,ansn,Mx;

void add(int u,int v,int D)
{
	to[++ tot] = v;
	next[tot] = g[u];
	d[tot] = D;
	g[u] = tot;
}

void Add(int u,int v)
{
	To[++ Tot] = v;
	Next[Tot] = G[u];
	G[u] = Tot;
}

int get(int x)
{
	if (f[x] != x) f[x] = get(f[x]);
	return f[x];
}

void dfs(int u)
{
	f[u] = u;
	p[u] = 1;
	for (int i = g[u];i;i = next[i])
	{
		int v = to[i];
		if (v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + d[i];
		dfs(v);
		f[v] = u;
	}
	for (int i = G[u];i;i = Next[i])
	{
		int v;
		if (u == Q[To[i]].u) v = Q[To[i]].v;
		else v = Q[To[i]].u;
		Q[To[i]].lca = get(v);
		if (p[v]) 
			Q[To[i]].ans = dep[u] + dep[v] - dep[get(v)] * 2;
	}
}

void init()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i < n;++ i)
	{
		int u,v,D;
		scanf("%d%d%d",&u,&v,&D);
		add(u,v,D);
		add(v,u,D);
	}
	for (int i = 1;i <= m;++ i)
	{
		scanf("%d%d",&Q[i].u,&Q[i].v);
		Add(Q[i].u,i);
		Add(Q[i].v,i);
	}
}

bool cmp(qry x,qry y)
{
	return x.ans < y.ans;
}

void bfs(int u)
{
	int l = 0,r = 1;
	a[1] = u;
	while (l < r)
	{
		u = a[++ l];
		for (int i = g[u];i;i = next[i])
		{
			int v = to[i];
			if (v == fa[u]) continue;
			a[++ r] = v;
		}
	}
}

void pre()
{
	dfs(1);
	sort(Q + 1,Q + 1 + m,cmp);
	bfs(1);
}

bool check(int Lim)
{
	memset(s,0,sizeof(s));
	int cur = 0;
	for (int i = m;i;i --)
		if (Q[i].ans <= Lim) break;
		else 
		{
			s[Q[i].u] ++,s[Q[i].v] ++;
			s[Q[i].lca] -= 2;
			cur ++;
		}
	int ans = 0;
	for (int i = n;i;-- i)
	{
		int u = a[i];
		if (s[u] == cur) 
			ans = max(ans,dep[u] - dep[fa[u]]);
		s[fa[u]] += s[u];
	}
	return Q[m].ans - ans <= Lim;
}

void solve()
{
	int l = 0,r = Q[m].ans;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d",l);
}

int main()
{
	freopen("transport.in","r",stdin);
	//freopen("transport.out","w",stdout);

	init();
	pre();
	solve();
}
