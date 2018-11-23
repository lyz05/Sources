//Problem D
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000+7,dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int a[N][N],cnt;
int n,m,x2,y2;
bool vis[N][N];

bool check(int x,int y)
{
	return (x>0&&y>0&&x<=n&&y<=m && (a[x][y]==0 || (x==x2 && y==y2)));
}

bool dfs(int x1,int y1,int fx)
{
	if (cnt>3) return 0;
	if (x1==x2 && y1==y2)
	{
		return 1;
	}
	for (int i=0;i<4;i ++)
	{
		int tx = x1+dir[i][0],ty = y1+dir[i][1];
		if (!check(tx,ty) || vis[tx][ty]) continue;
		vis[tx][ty] = 1;
		if (i!=fx) cnt ++;
		if (dfs(tx,ty,i)) return 1;
		if (i!=fx) cnt --;
		vis[tx][ty] = 0;
	}
	return 0;
}

int main()
{
	//freopen("D.in","r",stdin);
	while (1)
	{
		int Q;
		scanf("%d%d",&n,&m);
		if (n==0 && m==0) break;
		for (int i=1;i<=n;i ++)
			for (int j=1;j<=m;j ++)
				scanf("%d",&a[i][j]);
		scanf("%d",&Q);
		while (Q --)
		{
			int x1,y1;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			cnt = 0;
			memset(vis,0,sizeof vis);
			if (a[x1][y1]!=a[x2][y2] || a[x1][y1]==0) printf("NO\n");
			else if (dfs(x1,y1,-1)) printf("YES\n"); else printf("NO\n");
		}
	}
	return 0;
}
