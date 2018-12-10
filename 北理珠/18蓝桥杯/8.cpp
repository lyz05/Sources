#include<cstdio>
#include<cstring>
using namespace std;

const int N = 100+5,dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,x,y,cut,tot = 1,ans;
int a[N][N],vis[N][N];

bool judge(int x,int y)
{
	return (x>=0&&y>=0&&x<=n&&y<=m);
}

void dfs(int dep,int x,int y)
{
	for (int i=0;i<4;i ++)
	{
		int tx = x+dir[i][0],ty = y+dir[i][1];
		if (!judge(tx,ty) || a[x][y]!=a[tx][ty]) continue;
		cut ++;
		if (vis[tx][ty]) continue;
		vis[tx][ty] = 1;
		tot ++;
			dfs(dep+1,tx,ty);
		//tot --;
		//cut -= 2;
		//vis[tx][ty] = 0;
	}
}

int main()
{
	//freopen("8.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for (int i=0;i<n;i ++)
		for (int j=0;j<m;j ++)
			scanf("%d",&a[i][j]);
	memset(vis,0,sizeof vis);
	vis[x][y] = 1;
	dfs(1,x,y);	
	ans = tot*4-cut;
	printf("%d\n",ans);
	return 0;
} 