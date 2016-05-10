#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
LL n,m,k,p,mo,ans;

LL pow(LL x,LL y)
{
	x %= mo;
	LL ret = 1;
	while (y)
	{
		if (y&1) ret = (ret*x) % mo;
		x = (x*x) % mo;
		y >>= 1;
	}
	return ret;
}

int main()
{
	//freopen("box.in","r",stdin);
	//freopen("box.out","w",stdout);
	
	scanf("%I64d%I64d%I64d%I64d",&k,&n,&m,&p);
	mo = p;
	for (LL i=m;i<=n;i ++)
	{
		int sum = pow(i,k);
		ans = (ans+sum) % mo;
	}
	printf("%I64d\n",ans);
	return 0;
}
