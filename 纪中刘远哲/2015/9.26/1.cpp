#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int mo = 1e9+7;
typedef long long LL;
LL a1,q,n,ans;

LL pow(LL x,LL y)
{
	LL ret = 1;
	while (y)
	{
		if (y%2 == 1) (ret *= x) %= mo;
		x = (x*x)%mo;
		y = y>>1;
	}
	return ret;
}

int main()
{
	freopen("study.in","r",stdin);
	//freopen("study.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		scanf("%I64d%I64d%I64d",&a1,&q,&n);
		if (q == 1) ans = ((a1%mo) * (n%mo))%mo;
		else 
		{
			LL y = pow(1-q,mo-2),
			   x = ((a1%mo)*((1-pow(q%mo,n))%mo))%mo;
			ans = (x*y)%mo;
		}
		printf("%I64d\n",ans);
	}

	return 0;
}

