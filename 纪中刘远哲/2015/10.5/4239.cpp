#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 35,mod=1e9+7;
LL l,r;
int a;
LL ans;
int v[N];
LL f[N][2][10][10],g[N][2][10][10],s[N][2][10][10];

LL work(LL R)
{
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	memset(s,0,sizeof s);

	int len = 0;
	for (;R;R /= 10) v[++ len] = R % 10;
	f[len+1][1][0][0] = 1;
	for (int i=len+1;i>1;i --)
	for (int same=0;same<=1;same ++)
	for (int mo=0;mo<a;mo ++)
	for (int sum=0;sum<a;sum ++)
	{
		if (!f[i][same][mo][sum]) continue;
		for (int ch=0;ch<10;ch ++)
		{
			if (ch==a || (same && ch>v[i-1])) continue;
			int tsame=(same && ch == v[i-1]),tmo = (mo*10+ch)%a,tsum=(sum+ch)%a;
			(f[i-1][tsame][tmo][tsum]
				+= f[i][same][mo][sum])%= mod;
			(g[i-1][tsame][tmo][tsum]
				+= ((10*g[i][same][mo][sum])%mod+(f[i][same][mo][sum]*ch)%mod)%mod)%= mod;
			(s[i-1][tsame][tmo][tsum]
				+= ((100*s[i][same][mo][sum])%mod+((20ll * ch)%mod * g[i][same][mo][sum])%mod
				+((ch*ch)%mod*f[i][same][mo][sum])%mod)%mod) %=mod;
		}
	}
	

	LL ret = 0;
	for (int same=0;same<=1;same ++)
	for (int mo=1;mo<a;mo ++)
	for (int sum=1;sum<a;sum ++)
	{
		(ret += s[1][same][mo][sum])%=mod;
	}
	return ret;
}

int main()
{
	freopen("bachelor.in","r",stdin);
	//freopen("bachelor.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		ans = 0;
		scanf("%lld%lld%d",&l,&r,&a);
		ans = (work(r) - work(l-1) + mod) % mod;
		printf("%lld\n",ans);
	}

	return 0;
}

