#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int val[55][55],f[55][55][55][55];

int main()
{
	freopen("1493.in","r",stdin);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&val[i][j]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		for (int x=1;x<=n;x++)
			if (i+j-x>0 && i<x)
			{
			int y=i+j-x;
			f[i][j][x][y]=max(f[i][j][x][y],f[i-1][j][x-1][y]);
			f[i][j][x][y]=max(f[i][j][x][y],f[i-1][j][x][y-1]);
			f[i][j][x][y]=max(f[i][j][x][y],f[i][j-1][x-1][y]);
			f[i][j][x][y]=max(f[i][j][x][y],f[i][j-1][x][y-1]);
			f[i][j][x][y]+=val[i][j]+val[x][y];
			}
	printf("%d\n",f[n-1][m][n][m-1]);
	return 0;
}
