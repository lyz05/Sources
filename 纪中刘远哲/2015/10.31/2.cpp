#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

const int N = 100000+10;
struct node
{int y,w,next;} h[2*N];
stack <int> list;
int n,d,q,tot;
int e[N],dep[N],fa[N],w[N];
bool vis[N];

void add(int x,int y,int z)
{
	tot ++;
	h[tot].y = y;
	h[tot].w = z;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x)
{
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y;
		if (vis[y]) continue;
		vis[y] = 1;
		dep[y] = dep[x] + 1;
		fa[y] = x;
		w[y] = h[i].w;
		dfs(y);
	}
}

int lca(int u,int v)
{
	while (dep[u]>dep[v]) u = fa[u];
	while (dep[u]<dep[v]) v = fa[v];
	while (dep[u]==dep[v] && u!=v)
		u = fa[u],v = fa[v];
	return u;
}

int work(int u,int v,int k)
{
	int ret = 0,tmp = 0;
	while (u!=k)
	{
		if (tmp+w[u]>d) tmp = 0,ret ++;
		tmp += w[u];
		u = fa[u];
	}
	while (v!=k)
	{
		list.push(w[v]);
		v = fa[v];
	}
	while (!list.empty())
	{
		if (tmp+list.top()>d) tmp = 0,ret ++;
		tmp += list.top();
		list.pop();
	}
	if (tmp) ret ++;
	return ret;
}

int main()
{
	freopen("mancity.in","r",stdin);
	//freopen("mancity.out","w",stdout);

	scanf("%d%d%d",&n,&d,&q);
	for (int i=1;i<n;i ++)
	{
		int u=i+1,v,w;
		scanf("%d%d",&v,&w);
		add(u,v,w);add(v,u,w);
	}
	dep[1] = 1;vis[1] = 1;
	dfs(1);
	for (int i=1;i<=q;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int ans = work(u,v,lca(u,v));
		printf("%d\n",ans);
	}

	return 0;
}

