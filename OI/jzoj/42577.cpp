#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 50,M = 100;
int n,m,k,tot,ans;
int e[N],a[N];
struct node
{int y,next;}h[2*M];

void add(int x,int y)
{
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int dep)
{
	if (dep>n)
	{
		ans ++;
		return;
	}
	bool p[5];
	memset(p,1,sizeof p);
	for (int i=e[dep];i;i = h[i].next)
	{
		p[a[h[i].y]] = 0;
	}
	for (int i=1;i<=k;i ++)
	{
		if (!p[i]) continue;
		a[dep] = i;
			dfs(dep+1);
		a[dep] = 0;
	}
}

int main()
{
	freopen("42577.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
