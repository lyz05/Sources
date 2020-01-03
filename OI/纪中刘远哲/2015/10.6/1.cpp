#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int mo[2] = {2000000011 ,2000000063 };
const int N = 1e6;
bool p[N];
int pri[100005];
LL a[45];

void fj(LL x)
{
	for (int i=1;i<=pri[0] && x>=pri[i];i ++)
	{
		if (x % pri[i] ==0)
		{
			a[++ a[0]] = pri[i];
			while (x % pri[i] == 0) x /= pri[i];
		}
	}
	if (x != 1)
		a[++ a[0]] = x;
}

void prepar()
{
	memset(p,true,sizeof p);
	for (int i=2;i<N;i ++)
	{
		if (p[i])
		{
			for (int j=2;i*j<N;j++)
				p[i*j] = 0;
			pri[++ pri[0]] = i;
		}
	}
}

LL pow(LL x,LL y,int mo)
{
	x %= mo;
	LL ret = 1;
	while (y)
	{
		if (y % 2 == 1) ret = (ret * x) % mo;
		x = (x * x) % mo;
		y >>= 1;
	}
	return ret;
}

LL calc(int mo)
{
	LL ret = 1;
	for (int i=1;i<=a[0];i ++)
	{
		LL ret1 = ((a[i]-1)%mo * pow(a[i],mo-2,mo))%mo;
		ret = (ret * ret1) % mo;
	}
	return ret;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	
	LL a,b;
	prepar();
	scanf("%lld%lld",&a,&b);
	if (b==0) 
	{
		printf("1 1\n");
		return 0;
	}
	fj(a);
	for (int i=0;i<2;i ++)
	{
		LL ans = pow(a,b,mo[i]);
		ans = (ans * calc(mo[i])) % mo[i];
		printf("%lld ",ans);
	}
	printf("\n");

	return 0;
}
