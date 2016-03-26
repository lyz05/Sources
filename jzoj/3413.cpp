#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 100+5,M = 10000;
int map[N][N],sum[N][N],take[N][N],f[N][M];
int n,m;

int main()
{
	freopen("3413.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++)
	{
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j ++)
		{
			scanf("%d",&map[i][j]);
			sum[i][j] = sum[i][j-1]+map[i][j];
		}
		map[i][0] = k;
	}

	for (int i=1;i<=n;i++)
	{
		int c=map[i][0];
		for (int j=1;j<=c;j ++)
		{
			for (int k=0;k<=j;k ++)
				take[i][j] = max(take[i][j],sum[i][k]+sum[i][c]-sum[i][c-j+k]);
		}
	}
	
	for (int i = 1;i <= n;i ++)
	{
		int c=map[i][0];
		for (int j = 1;j <= m;j++)
			for (int k = 0;k <= c;k ++)
			{
				if (j-k<0) continue;
				f[i][j] = max(f[i][j],f[i-1][j-k]+take[i][k]);
			}
	}

	printf("%d\n",f[n][m]);
}
