#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 100000, mo = 998244353;
struct node
{
	int f,tag;
};
int n,m,len;
LL f[N],a[N];
LL ans;

LL pow(LL x,LL y)
{
	LL ret = 1;
	while (y)
	{
		if (y%2 == 1) (ret *= x)%=mo;
		x=(x*x)%mo;
		y >>= 1;
	}
	return ret;
}

int gcd(int x,int y)
{if (y==0) return x;else return gcd(y,x%y);}

void make()
{
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
			a[gcd(i,j)] ++;
}
LL work()
{
	LL ret=1;	
	for (int i=1;i<=len;i ++)
	{
		(ret *= pow(f[i],a[i]))%=mo;
	}
	return ret;
}
int main()
{
	freopen("3.in","r",stdin);
	//freopen("3.out","w",stdout);
	
	int T = 0;
	scanf("%d%d",&n,&m);
	len = min(n,m);
	for (int i=1;i<=len;i++) scanf("%lld",&f[i]);
	scanf("%d",&T);

	make();
	printf("%lld\n",work());
	while (T --)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		for (int i=x;i<=y;i ++) (f[i] *= z)%=mo;
		printf("%lld\n",work());
	}
	return 0;
}
