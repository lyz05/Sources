#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 100000;
int n;
LL a[N],s[N];

LL gcd(LL x, LL y)
{
	if (y == 0) return x;
	else 
	{
		return gcd(y,x % y);
	}
}

int main()
{
	//freopen("3478.in","r",stdin);

	scanf("%d",&n);
	for (int i = 1; i <= n ; i ++)
	{
		scanf("%lld",&a[i]);
		a[0] += a[i];
	}
	sort(a + 1 , a + 1 + n);
	LL ans = 0;
	for (int i = 2 ; i <= n ; i ++)
	{
		s[i] = s[i-1] + (i-1) * (a[i] - a[i-1]);
		ans += s[i];
	}
	ans = 2*ans+a[0];
	LL t = gcd(ans,n);
	printf("%lld %lld\n",ans/t,n/t);
	return 0;
}

