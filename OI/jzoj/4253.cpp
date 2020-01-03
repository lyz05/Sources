#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 100000+10, M = 1000000+10;
int ans[N],e[2][N],rd[N],next[2][M],to[2][M],v[N],h[N];
int dfn[N],low[N],col[N],stack[N],sum[N],f[N],tot[2];
bool p[N],instack[N];
int n,m,k,Index,top,ctot;

bool cmp(int x,int y) {return x>y;}

void add(int x,int y,int kind)
{
	tot[kind] ++;
	to[kind][tot[kind]] = y;
	next[kind][tot[kind]] = e[kind][x];
	e[kind][x] = tot[kind];
}

int gf(int x)
{
	if (x!=h[x]) h[x] = gf(h[x]);
	return h[x];
}

void link(int x,int y)
{
	int i=gf(x), j=gf(y);
 	if (i!=j) h[i]=j;
}

void tarjan(int x,int kind)
{
	dfn[x] = low[x] = ++ Index;
	instack[x] = 1;
	stack[++ top] = x;
	for (int i=e[kind][x];i;i=next[kind][i])
	{
		int y = to[kind][i];
		if (col[y]) continue;
		if (instack[y]) low[x] = min(low[x],dfn[y]);
		else {tarjan(y,kind);low[x]=min(low[x],low[y]);}
	}
	if (dfn[x]==low[x])
	{
		int y;
		ctot ++;
		do
		{
			y = stack[top --];
			instack[y] = 0;
			sum[ctot] += v[y];
			col[y] = ctot;
		} while (y!=x);
	}
}

void work(int x,int kind)
{
	p[x] = 1;
	f[x] += sum[x];
	for (int i=e[kind][x];i;i=next[kind][i])
	{
		int y = to[kind][i];
		link(x,y);
		rd[y] --;
		f[y] = max(f[y],f[x]);
		if (rd[y]==0) work(y,kind);
	}

}

int main()
{
	freopen("4253.in","r",stdin);
	//freopen("azeroth.out","w",stdout);	


	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if (u==v) continue;
		add(u,v,0);
	}
	for (int i=1;i<=n;i ++)	scanf("%d",&v[i]);
	scanf("%d",&k);

	for (int i=1;i<=n;i ++) if (!col[i]) tarjan(i,0);


	for (int j=1;j<=n;j ++)
		for (int i=e[0][j];i;i=next[0][i])
		{
			int u = j,v = to[0][i];
			if (col[u]!=col[v])
			{
				add(col[u],col[v],1);
				rd[col[v]] ++;
			}
		}
	//¹¹ÔìÐÂÍ¼
	for (int i=1;i<=ctot;i ++) h[i] = i;
	for (int i=1;i<=ctot;i ++) 
		if (rd[i] == 0 && !p[i]) 
			work(i,1);
	for (int i=1;i<=ctot;i ++)
	{
		ans[gf(i)] = max(ans[gf(i)],f[i]);
	}
	sort(ans+1,ans+1+ctot,cmp);
	for (int i=1;i<=min(k+1,ctot);i ++)
		ans[0] += ans[i];
	printf("%d\n",ans[0]);

	return 0;
}
