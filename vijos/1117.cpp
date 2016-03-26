#include <cstdio>

using namespace std;

int n,k,f[220][10];

int main()
{
	scanf("%d%d",&n,&k);
	f[0][0] = 1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
			if (i>=j) f[i][j] = f[i-1][j-1] + f[i-j][j];
	}
	printf("%d\n",f[n][k]);
	return 0;
}
