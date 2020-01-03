#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100000, M = 1000000;
int ans[N],e[N],rd[N],next[M],to[M],v[N],h[N];
bool vis[N];
int n,m,tot,k;

bool cmp(int x,int y){return x>y;}

void add(int x,int y)
{
	tot ++;
	to[tot] = y;
	next[tot] = e[x];
	e[x] = tot;
	rd[y] ++;
}

int dfs(int x)
{
	vis[x] = 1;
	int ret = 0;
	for (int i=e[x];i;i=next[i])
	{
		if (!vis[to[i]])
			ret = max(ret,dfs(to[i]));	
	}
	ret += v[x];
	vis[x] = 0;
	return ret;
}

int gf(int x)
{
	if (x==h[x]) return x;
	h[x] = gf(h[x]);
	return h[x];
}

void link(int x,int y)
{
	int i=gf(x), j=gf(y);
 	if (i!=j) h[i]=j;
}

int main()
{
	freopen("azeroth.in","r",stdin);
	//freopen("azeroth.out","w",stdout);	


	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) h[i] = i;
	for (int i=1;i<=m;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);link(u,v);
	}
	for (int i=1;i<=n;i ++)	scanf("%d",v + i);
	scanf("%d",&k);

	for (int i=1;i<=n;i ++) 
		if (!rd[i]) ans[gf(i)] = max(ans[gf(i)],dfs(i));
	for (int i=1;i<=n;i ++)
		if (!ans[gf(i)]) ans[gf(i)] = max(ans[gf(i)],dfs(i));
	sort(ans+1,ans+1+n,cmp);
	
	for (int i=1;i<=k+1;i ++)
		ans[0] += ans[i];
	printf("%d\n",ans[0]);

	return 0;
}

