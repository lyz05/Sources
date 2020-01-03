#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105;
int map[N][N],ans[N];
int n,m;

int main()
{
	freopen("3.in","r",stdin);
	//freopen("3.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		map[x][y] = map[y][x] = z;
	}

	for (int k=1;k<=n;k ++)
		for (int i=1;i<=n;i ++)
			for (int j=1;j<=n;j ++)
			{
				if (i==j || i==k || j==k || !map[i][k] || !map[k][j]) continue;
				if (map[i][j]==0) map[i][j]=map[i][k]+map[k][j];
				else map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
			}

	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=n;j ++)
		{
			if (i!=j && map[i][j]%2==1)
			{
				ans[i]++,ans[j]++;
				for (int k=1;k<=n;k ++)
				{
					if (k==i || k==j) continue;
					if (map[i][j]==0 || map[i][k]==0 || map[k][j]==0) 
						continue;
					if (map[i][j]==map[i][k]+map[k][j]) 
						ans[k] ++;
				}
			}
		}
	}

	for (int i=1;i<=n;i ++) printf("%d\n",ans[i]);
	return 0;
}
