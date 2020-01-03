#include <cstdio>
#include <algorithm>

const int N = 100000+5,M = 200000+5;
struct node
{
	int y,next;
} h[2*M];
int n,m,tot,ans,tot1;
int fa[N],x[M],y[M],fat[N],dep[N],e[N],vis[N];

int gf(int x)
{
	if (x==fa[x]) return x;
	else return fa[x] = gf(fa[x]);
}
void prepar(){for (int i=1;i<=n;i ++) fa[i] = i;}
void add(int x,int y)
{
	tot1 ++;
	h[tot1].y = y;
	h[tot1].next = e[x];
	e[x] = tot1;
}
void dfs(int x)
{
	vis[x] = 1;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		if (vis[y]) continue;
		fat[y] = x;
		dep[y] = dep[x] + 1;
		dfs(y);
	}
}

void jump(int &x)
{
	int i = gf(x),j = gf(fat[x]);
	if (i!=j)
	{
		ans --;
		fa[i] = j;
	}
	x = gf(x);
}

void work(int x,int y)
{
	while (x!=y)
	{
		while (dep[x]>dep[y]) jump(x);
		while (dep[x]<dep[y]) jump(y);
		while (dep[x]==dep[y] && x!=y) jump(x),jump(y);
	}

}
int main()
{
	freopen("graph.in","r",stdin);
	//freopen("graph.out","w",stdout);

	scanf("%d%d",&n,&m);
	prepar();
	for (int i=1;i<=m;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int j = gf(u),k = gf(v);
		if (j!=k) fa[j] = k, add(u,v), add(v,u);
		else x[++ tot] = u,y[tot] = v;
	}
	dep[1] = 1;
	dfs(1);
	prepar();
	ans = n-1;
	while (tot --) 
	{
		work(x[tot+1],y[tot+1]);
	}
	int T;
	scanf("%d",&T);
	while (T --)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		work(u,v);
		printf("%d\n",ans);
	}
	return 0;
}
