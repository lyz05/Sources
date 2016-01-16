#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105,INF = 1e9+7;
typedef int Matrix[N][N];
int n,m,D,A,B;
Matrix map[3];

void floyd(Matrix a)
{
	for (int k=1;k<=n;k ++)
	for (int i=1;i<=n;i ++)
	if (i!=k && a[i][k]!=-1)
	for (int j=1;j<=n;j ++)
	if (i!=j && j!=k && a[k][j]!=-1)
	{
		if (a[i][j]==-1) a[i][j] = a[i][k]+a[k][j];
		else a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
	}
}

int getans()
{
	if (map[1][A][B]!=-1) return 0;
	int ret = INF;
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
		if ((map[1][A][i]!=-1 || A==i) && (map[1][B][j]!=-1 || B==j)
			&& i!=j)
		{
			if (map[2][i][j]!=-1)
				ret = min(ret,map[2][i][j]);
		}
	return ret;
}

void init()
{
	memset(map,255,sizeof map);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		map[0][x][y] = map[0][y][x] = z;
		map[2][x][y] = map[2][y][x] = 0;
	}
	memcpy(map[1],map[0],sizeof map[0]);
	scanf("%d",&D);
	for (int i=1;i<=D;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[1][x][y] = map[1][y][x] = -1;
		map[2][x][y] = map[2][y][x] = map[0][x][y];
	}
	scanf("%d%d",&A,&B);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	init();	
	floyd(map[1]);
	floyd(map[2]);
	printf("%d\n",getans());
	return 0;
}
