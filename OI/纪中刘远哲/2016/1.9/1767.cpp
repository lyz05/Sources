#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 55*2;
int n,cnt;
int f[N][N],g[N][N],a[N][2];
int ans[N];

int main()
{
	freopen("1767.in","r",stdin);
	//freopen("1767.out","w",stdout);

	scanf("%d\n",&n);
	for (int i=1;i<=n;i ++)
	{
		char ch;int num;
		scanf("%c %d ",&ch,&num);
		a[i][0] = a[i+n][0] = num;
		a[i][1] = a[i+n][1] = (ch=='t');
	}
	//f[i][j] = max(f[i][k]+*f[i+k][j-k]);k=1 to j-1
	memset(f,128,sizeof f);
	memset(g,127,sizeof g);
	for (int i=1;i<=2*n;i ++) f[i][1] = g[i][1] = a[i][0];
	
	for (int j=2;j<=n;j ++)
	for (int i=1;i<=2*n && i+j-1<=2*n;i ++)
	for (int k=1;k<j;k ++)
	{
		int id = i+k;
		int v1,v2,v3,v4;
		if (a[id][1])
		{
			v1 = f[i][k]+f[i+k][j-k];
			v2 = g[i][k]+g[i+k][j-k];
			v3 = f[i][k]+g[i+k][j-k];
			v4 = g[i][k]+f[i+k][j-k];
		} else 
		{
			v1 = f[i][k]*f[i+k][j-k];
			v2 = g[i][k]*g[i+k][j-k];
			v3 = f[i][k]*g[i+k][j-k];
			v4 = g[i][k]*f[i+k][j-k];
		}
		f[i][j] = max(f[i][j],max(max(v1,v2),max(v3,v4)));
		g[i][j] = min(g[i][j],min(min(v1,v2),min(v3,v4)));
	}
	for (int i=1;i<=n;i ++) 
	{
		if (f[i][n]>ans[0])
			ans[0] = f[i][n],cnt = 0;
		if (f[i][n]==ans[0]) ans[++ cnt] = i;
	}
	printf("%d\n",ans[0]);
	for (int i=1;i<=cnt;i ++) printf("%d ",ans[i]);
	puts("");
	return 0;
}
