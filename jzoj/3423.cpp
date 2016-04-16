#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 205;
int n,m,ans;
int a[N][N],f[N],vis[N];

bool dfs(int x)
{
	for (int y=1;y<=n;y ++)
	{
		if (!vis[y] && a[x][y])
		{
			vis[y] = 1;
			if (!f[y] || dfs(f[y]))
			{
				f[y] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	freopen("3423.in","r",stdin);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y] = 1;
	}

	for (int k=1;k<=n;k ++)
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
	if (i!=j && i!=k && j!=k)
		a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
	
	memset(f,0,sizeof f);
	for (int i=1;i<=n;i ++)
	{
		memset(vis,0,sizeof vis);
		if (dfs(i)) 
			ans ++;
	}
	printf("%d\n",n-ans);

	return 0;
}
