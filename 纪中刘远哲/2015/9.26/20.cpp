#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100000;
int f[N][4];
int n,k;

int main()
{
	freopen("body.in","r",stdin);
	//freopen("body.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i ++)
		scanf("%d",&f[i][1]);
	for (int i=1;i<=n;i ++)
		scanf("%d",&f[i][2]) , f[i][3] = 1;
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=i-1;j++)
		{
			int x = f[i][1], y = f[i][2];
			double last ,now;
			int tx = x + f[j][1],
			    ty = y + f[j][2];
			if (y) last = 1.0*x/y;
			if (ty) now = 1.0*tx/ty;
			if (now>last && f[i][3]<k)
			{
				f[i][1] = tx;f[i][2] = ty;f[i][3] ++;
			}
		}
	}
	double ans = 1.0*f[n][1]/f[n][2];
	printf("%.3lf\n",ans);
	return 0;
}

