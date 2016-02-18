#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
LL ans;
int n;

LL phi(int n)
{
	LL ret = n;
	for (int i=2;i<=sqrt(n);i ++)
	{
		if (n%i==0)
		{
			ret = ret/i*(i-1);
			while (n%i==0) n /= i;
		}
	}
	if (n>1) ret = ret/n*(n-1);
	return ret;
}

int main()
{
	//freopen("1164.in","r",stdin);
	//freopen("1164.out","w",stdout);

	while (scanf("%d",&n)!=EOF)
	{
		LL ans;
		if (n==1) ans = 1; else ans = phi(n)*n/2;
		printf("%lld\n",ans);
	}
	return 0;
}
