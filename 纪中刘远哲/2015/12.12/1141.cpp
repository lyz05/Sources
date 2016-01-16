#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105,INF = 2088533116;
int n,m,T;
int a[N][N];


int main()
{
	//freopen("1141.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&m);
	memset(a,124,sizeof a);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x][y] = a[y][x] = z;
	}
	for (int k=1;k<=n;k ++)
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
	{
		int w = min(a[i][k],a[k][j]);
		a[i][j] = max(a[i][j],w);
	}
	scanf("%d",&T);
	while (T --)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",(a[x][y]==INF)?-1:a[x][y]);
	}
	return 0;
}
