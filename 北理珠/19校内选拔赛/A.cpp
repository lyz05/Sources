#include <cstdio>
using namespace std;
typedef long long LL;

LL n;

LL calc(LL n)
{
	int cnt = 0;
	for (LL i=1;n;i<<=1)
	{
		if (n&i)
		{
			n -= n&i;
			cnt ++;
		}
	}
	return cnt;
}

int main()
{
	while (~scanf("%lld",&n))
	{
		LL ans = n-calc(n);
		printf("%lld\n",ans);
	}
	return 0;
} 
