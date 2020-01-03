#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

typedef long long LL;
const int N = 1e5+7;//5e6+7
int now,i,len,begin,mo;
LL n,m,k;
int a[N+N][2];
int p[2][N+N];
//map <int,int>p[2];

LL pow(LL x,LL y)
{
	LL ret = 1;
	while (y)
	{
		if (y%2==1) (ret *= x)%=mo;
		x = (x*x)%mo;
		y >>= 1;
	}
	return ret;
}

int main()
{
	freopen("sesame.in","r",stdin);
	freopen("sesame.out","w",stdout);

	scanf("%lld%lld%lld",&n,&m,&k);
	mo = n+m;
	n = (n*pow(2,k)) % mo;
	m = (m*pow(2,k)) % mo;
	if (n<m) printf("%lld\n",n);else printf("%lld\n",m);
	
	return 0;
}