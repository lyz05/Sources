#include <cstdio>
#include <algorithm>
using namespace std;
const int N=30000+100,M=30000+100;

struct node{int x,y,d;}c[N];
struct node1{int y,v,next;}h[2*M];
int n,m,k,u,v,tot,e[N],fw[N][16],fv[N][16],fa[N],dep[N];

bool cmp(node a, node b) {return a.d<b.d;}

int gf(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = gf(fa[x]);
}

void add(int x,int y,int z)
{
	tot ++;
	h[tot].y = y;
	h[tot].v = z;
	h[tot].next=e[x];
	e[x] = tot;
}

void dfs(int x ,int fat)
{
	for (int i = e[x];i;i = h[i].next)
		if (h[i].y!=fat)
		{
			dep[h[i].y] = dep[x]+1;
			dfs(h[i].y,x);
			fv[h[i].y][0] = h[i].v;
			fw[h[i].y][0] = x;
		}
}

int move(int &x,int d)
{
	int i,t=0;
	while (dep[fw[x][0]]!=d)
	{
		for (i = 0;dep[fw[x][i]]>d;i++);
		t = max(t,fv[x][i-1]);
		x = fw[x][i-1];
	}
	t = max(t,fv[x][0]);
	x = fw[x][0];
	return t;
}

int lca(int u,int v)
{
	int i,t = 0;
	if (dep[u]>dep[v]) t = move(u,dep[v]);
	else if (dep[u]<dep[v]) t = move(v,dep[u]);
	while (fw[u][0]!=fw[v][0])
	{
		for (i = 0;fw[u][i] != fw[v][i];i ++);
		t = max(t,max(fv[u][i-1],fv[v][i-1]));
		u = fw[u][i-1];
		v = fw[v][i-1];
	}
	if (u!=v) 
		t = max(max(fv[u][0],fv[v][0]),t);
	return t;
}

int main()
{
	freopen("1738.in","r",stdin);

	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i <= m ; i ++) 
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].d);
	sort(c+1,c+1+m,cmp);
	for (int i=1 ; i <= n ; i ++) fa[i]=i;
	for (int i=1 ; i <= m ; i ++)
	{
		if (gf(c[i].x)!=gf(c[i].y))
		{
			add(c[i].x,c[i].y,c[i].d);
			add(c[i].y,c[i].x,c[i].d);
			fa[fa[c[i].x]] = fa[fa[c[i].y]];
		}
	}
	dep[1] = 1;
	dfs(1,0);
	for (int j=1 ; j <= 14; j ++)
		for (int i=1 ;i<=n;i ++)
			if (fw[fw[i][j-1]][j-1] != 0)//limit excepeted
			{
				fw[i][j] = fw[fw[i][j-1]][j-1];
				fv[i][j] = max(fv[i][j-1],fv[fw[i][j-1]][j-1]);
			}
	for (int i = 1 ; i <= k ; i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}

	return 0;
}
