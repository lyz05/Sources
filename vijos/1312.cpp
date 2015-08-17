#include <cstdio>
#include <algorithm>

using namespace std;

const int N=100+2;
int n;
int e[2*N],f[2*N][2*N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&e[i]);
		e[n+i]=e[i];
	}
	for (int j=2;j<=2*n-1;j++)
		for (int i=j-1;i>0 && j-i<n;i--)
			for (int k=i;k<j;k++)
			{
				f[i][j]=max(f[i][k]+f[k+1][j]+e[i]*e[k+1]*e[j+1],f[i][j]);
			}
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,f[i][i+n-1]);
	printf("%d\n",ans);

	return 0;
}
