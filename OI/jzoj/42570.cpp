#include <cstdio>
using namespace std;

typedef long long LL;
const int N = 2+5;
LL n,m;
LL f[N],ans;

LL pow(LL x,LL y)
{
	LL ret = 1;
	while (y)
	{
		if (y%2 == 1) (ret *= x);
		x = (x*x);
		y >>= 1;
	}
	return ret;
}

int main()
{
	//freopen("color.in","r",stdin);
	//freopen("color.out","w",stdout);

	scanf("%lld%lld",&n,&m);	
	f[1] = m;f[2] = m*(m-1);
	if (n<=2) 
	{
		printf("%lld\n",f[n]);
		return 0;
	}
	ans = (pow(-1,n-2)*(m-1)+pow(m-1,n));
	printf("%lld\n",ans);
	return 0;
}


