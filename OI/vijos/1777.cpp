#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 505,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int n,m,map[N][N],vis[N][N],p[N],num1[N][N],num2[N][N];
int k,kk;

bool judge(int x,int y)
{
	return x>0 && y>0 && x<=n && y<=m;
}

void dfs(int x,int y,int &from)
{
	if (x==1) p[y] = 0;
	if (x==n) num1[y][++ num1[y][0]] = from;
	for (int i=0;i<4;i ++)
	{
		int tx = x + dir[i][0],ty = y + dir[i][1];
		if (judge(tx,ty) && !vis[tx][ty] && map[x][y]>map[tx][ty])
		{
			vis[tx][ty] = 1;
			dfs(tx,ty,from);
		}
	}
}

int main()
{
	freopen("1777.in","r",stdin);
	//freopen("1777.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=m;j ++) 
		scanf("%d",&map[i][j]);
	memset(p,1,sizeof p);
	for (int i=1;i<=m;i ++)
	{
		if (p[i])
		{
			memset(vis,0,sizeof vis);
			dfs(1,i,i);
		}
	}
	int ans = 0;
	for (int i=1;i<=m;i ++) 
		if (num1[i][0]==0) ans ++;
	if (ans) 
	{
		printf("0\n%d\n",ans);
		exit(0);
	}
	
	memset(p,1,sizeof p);
	for (ans = 0;k<m;ans ++)
	{
		memset(num2,0,sizeof num2);
		for (int i=1;i<=m;i ++)
		if (p[i])
		for (int j=1;j<=num1[i][0];j ++)
			num2[num1[i][j]][++ num2[num1[i][j]][0]] = i;
		int max = -1e9+7;
		for (int i=1;i<=m;i ++)
			if (num2[i][0]>max)
			{
				max = num2[i][0];
				kk = i;
			}
		for (int i=1;i<=num2[kk][0];i ++) p[num2[kk][i]] = 0, k ++;
	}
	printf("1\n%d\n",ans);
	return 0;
}
