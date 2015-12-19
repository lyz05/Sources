#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 205;
int a[N][N],dis[N][N],n,m,s;
int fa[N],num[N],son[N][N],d[N];
double f[N][N],p[N][N],g[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i ++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v] = a[v][u] = dis[u][v] = dis[v][u] = w;
	}
	scanf("%d",&s);
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=s;j ++)
			scanf("%lf",&p[i][j]);

	for (int k=1;k<=n;k ++)
	for (int i=1;i<=n;i ++)
	if (i!=k) 
	for (int j=1;j<=n;j ++)
	if (i!=j && j!=k && dis[i][k] && dis[k][j])
		if (!dis[i][j] || dis[i][k]+dis[k][j]<dis[i][j])
			dis[i][j] = dis[i][k] + dis[k][j];
	//floyd
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=n;j ++)
			if (i!=j && a[i][j] && dis[1][i]+a[i][j]==dis[1][j])
				fa[j]=i,num[i]++,son[i][++ son[i][0]]=j;
	//½¨Ê÷
	int top = 0,tail = 0;
	for (int i=1;i<=n;i ++)
		if (num[i] == 0) d[++ tail] = i;
	while (top<tail)
	{
		int x = d[++ top];
		if (son[x][0] == 0)
		{
			for (int i=1;i<=s;i ++)
				f[x][i] = p[x][i];
		} else 
		{
			memset(g,0,sizeof g);
			for (int i=1;i<=s;i ++)
				g[1][i] = f[son[x][1]][i];
			for (int i=2;i<=son[x][0];i ++)
			for (int j=0;j<=s;j ++)
			for (int k=0;k<=j;k ++)
				g[i][j] = max(g[i][j],g[i-1][k]+f[son[x][i]][j-k]);
			for (int i=1;i<=s;i ++)
				g[son[x][0]][i] /= son[x][0]+0.0;
			for (int i=1;i<=s;i ++)
				for (int j=0;j<=i;j ++)
					f[x][i] = max(f[x][i],p[x][j]+(1-p[x][j])*g[son[x][0]][i-j]);
		}
		num[fa[x]] --;
		if (num[fa[x]] == 0) d[++ tail] = fa[x];
	}
	printf("%.4lf\n",f[1][s]);

	return 0;
}
