#include <cstdio>
#include <cstring>
using namespace std;

const int N = 20+5;
char map[N][N];
int n,m,ans,dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool vis[N][N];

bool judge(int x,int y)
{
	return (x>=0 && y>=0 && x<m && y<n);
}

void dfs(int x,int y)
{
	for (int i=0;i<4;i ++)
	{
		int tx = x+dir[i][0],ty = y+dir[i][1];
		if (judge(tx,ty) && map[tx][ty]=='.' && !vis[tx][ty])
		{
			ans ++;
			vis[tx][ty] = 1;
			dfs(tx,ty);
		}
	}
}

int main()
{
	freopen("A.in","r",stdin);
	while (1)
	{
		int x,y;
		memset(map,0,sizeof map);
		memset(vis,0,sizeof vis);
		scanf("%d%d\n",&n,&m);
		if (n==0 && m==0) break;
		for (int i=0;i<m;i ++)
		{
			for (int j=0;j<n;j ++)
			{
				scanf("%c",&map[i][j]);
				if (map[i][j]=='@') x = i,y = j;
			}
			scanf("\n");
		}
		ans = 1;
		vis[x][y] = 1;
		dfs(x,y);
		printf("%d\n",ans);
	}
	return 0;
}
