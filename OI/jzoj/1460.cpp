#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
LL n,k,tmp,x3,y3,a,b,p;
int ans[1000];

LL gcd(LL a,LL b)
{
	if (!b)
	{
		x3 = 2/a;
		y3 = 0;
		return a;
	}
	LL ret = gcd(b,a%b),t = x3;
	x3 = y3;
	y3 = t-a/b*y3;
	return ret;
}
void work(LL a,LL b)
{
	p = gcd(a,b);
	if (2%p!=0) return;
	LL x = a*x3-b*y3;
	//if (x%2==1) return;
	LL t = 2*a*b/p;
	double kmin = 1.0*(2-a*x3+b*y3)/t,
	       kmax = 1.0*(2*n-a*x3+b*y3)/t;
       	for (int k=ceil(kmin);k<=floor(kmax);k ++)
	{
		ans[++ ans[0]] = x/2+a*b*k/p;
	}
}

int main()
{
	freopen("1460.in","r",stdin);
	//freopen("1460.out","w",stdout);

	scanf("%lld",&n);
	if (n==1) return 0;
	for (int i=1;i<=sqrt(n);i ++)
	{
		if (n%i==0)
		{
			a = i;b = n/i;
			work(a,b);work(b,a);
		}
	}
	sort(ans+1,ans+1+ans[0]);

	printf("%d\n",ans[1]);
	for (int i=2;i<=ans[0];i ++) 
		if (ans[i]!=ans[i-1]) printf("%d\n",ans[i]);
	return 0;
}
