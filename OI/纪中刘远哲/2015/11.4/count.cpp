#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int mo = 998244353;
LL k,ans;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	ans = 0;
	scanf("%lld",&k);
	for (LL i=1;i*i<k;i ++)
		(ans += (k/i-i)%mo)%=mo;
	(ans *= 2)%=mo;
	LL x = sqrt(k);
	(ans += x)%=mo;

	printf("%lld\n",ans);
	return 0;
}

