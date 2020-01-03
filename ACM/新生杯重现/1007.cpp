#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 105,dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int a[N][N],vis[N][N];
int n,m,res = 0;
bool flag = 0;

bool judge(int x,int y)
{
	return (x>=1 && y>=1 && x<=n && y<=n);
}

void dfs(int x,int y)
{
	res += a[x][y];
	vis[x][y]=1;
	for (int i=0;i<4;i ++)
	{
		int tx = x+dir[i][0],ty = y+dir[i][1];
		if (judge(tx,ty) && a[tx][ty] && !vis[tx][ty])
		{
			dfs(tx,ty);
		}
	}
}

int main()
{
	while (1)
	{
		flag = 0;
		memset(vis,0,sizeof vis);
		scanf("%d%d",&n,&m);
		if (n==0 && m==0) break;
		for (int i=1;i<=n;i ++)
			for (int j=1;j<=n;j ++)
				scanf("%d",&a[i][j]);
		for (int i=1;i<=n;i ++)
			for (int j=1;j<=n;j ++)
			{
				res = 0;
				if (a[i][j]) dfs(i,j);
				if (res==m) flag = 1;
			}
		if (flag) printf("YES"); else printf("NO");
		printf("\n");
	}
	return 0;
}