#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
int d,a,b;
LL n;

LL half()
{
	LL L = a,R = a+d*n,ret = 0;
	while (L<=R)
	{
		LL mid = (L+R)/2;
		LL t = (mid-a)/d+((mid-a)%d != 0);
		if (b+(n-t)*d>=mid) 
		{
			L = mid + 1;
			ret = mid;
		}else R = mid - 1;
	}
	return ret;
}

int main()
{
	freopen("4303.in","r",stdin);
	//freopen("mountain.out","w",stdout);

	scanf("%lld %d %d %d",&n,&d,&a,&b);
	n --;
	printf("%lld\n",half());

	return 0;
}
