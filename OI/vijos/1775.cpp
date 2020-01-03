#include <cstdio>
#include <algorithm>

using namespace std;

const int N=350+5,M=45+1;
int n,m;
int map[N],b[5],f[M][M][M][M];

int main()
{
	freopen("1775.in","r",stdin);
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&map[i]);
	for (int i=1;i<=m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		b[tmp]++;
	}

	for (int t=0;t<=b[1];t++)
	for (int i=0;i<=b[2];i++)
		for (int j=0;j<=b[3];j++)
		for (int k=0;k<=b[4];k++)
		{
			if (t) f[t][i][j][k]=max(f[t][i][j][k],f[t-1][i][j][k]);
			if (i) f[t][i][j][k]=max(f[t][i][j][k],f[t][i-1][j][k]);
			if (j) f[t][i][j][k]=max(f[t][i][j][k],f[t][i][j-1][k]);
			if (k) f[t][i][j][k]=max(f[t][i][j][k],f[t][i][j][k-1]);
			f[t][i][j][k]+=map[t*1+i*2+j*3+k*4];
		}
	int ans=f[b[1]][b[2]][b[3]][b[4]];
	printf("%d\n",ans);
}
