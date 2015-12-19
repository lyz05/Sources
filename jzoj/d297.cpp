#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 100000+10,mo = 998244353;
int n,m,len;
LL f[N],g[N],s[N],ans;

LL pow(LL x,LL y)
{
	x %= mo;
	int ret = 1;
	while (y)
	{
		if (y % 2==1) ret = (ret*x) % mo;
		x = (x*x)%mo;
		y >>= 1;
	}
	return ret;
}

int main()
{
	freopen("d297.in","r",stdin);
	//freopen("help3.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	len = min(n,m);
	for (int i=1;i<=len;i ++) scanf("%lld",f + i);

	ans = 1;
	for (int i=len;i>=1;i --)
	{
		g[i] = (LL)(n/i) * (m/i);
		for (int j=2;i*j<=len;j ++)
			g[i] -= g[i*j];
	}
	for (int i=1;i<=len;i ++) 
	{
		s[i] = s[i-1] + g[i];
		(ans *= pow(f[i],g[i]))%=mo;
	}
	printf("%lld\n",ans);
	int T;
	scanf("%d",&T);
	while (T --)
	{
		LL x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		(ans *= pow(z,s[y]-s[x-1]))%=mo;
		printf("%lld\n",ans);
	}
}
