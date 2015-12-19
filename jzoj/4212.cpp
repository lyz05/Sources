#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 2005, mo = 258280327;

LL f[N][N],ans,t1[N];

LL pow(LL x,LL y)
{
	LL ans = 1;
	while (y)
	{
		if (y & 1) ans = (ans*x) % mo;
		x = (x*x) % mo;
		y >>= 1;
	}
	return ans;
}


int main()
{
	freopen("4212.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T --)
	{
		LL n,x,y;
		scanf("%lld%lld%lld",&n,&x,&y);
		LL ny = pow(y,mo-2);
		memset(f,0,sizeof f);
		f[1][0] = 1;
		t1[0] = 1;
		for (int i=1;i<=n;i++) t1[i] = (t1[i-1]*(y-x)%mo*ny%mo)%mo;
		for (int i=2;i<=n;i++)
			for (int j=0;j<=n-1;j++)
			{
				f[i][j] = 
				(f[i][j]+f[i-1][j]*((1-t1[j]+mo)%mo)%mo)%mo;
				if (j)
				f[i][j] = (f[i][j]+f[i-1][j-1]*t1[j]%mo)%mo;
			}
		for (int j=0;j<=n-1;j++)
		{
			ans = 0;
			for (int i=1;i<=n;i++) ans = (ans+f[i][j])%mo;
			printf("%lld ",ans*pow(n,mo-2)%mo);
		}
		printf("\n");
	}
	return 0;
}
