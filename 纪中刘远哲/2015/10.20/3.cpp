#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n,k;
long long ans;

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);

	ans = 1;
	scanf("%d%d",&n,&k);
	if (k==1)
	{
		puts("0");
		return 0;
	}	
	if (n==1)
	{
		ans = k;
		for (int i=1;i<=19;i ++)
			ans *= (k-1);
	}
	if (n==2)
	{
		if (k<3) ans = 0;

	}
	printf("%lld\n",ans);
	return 0;
}
