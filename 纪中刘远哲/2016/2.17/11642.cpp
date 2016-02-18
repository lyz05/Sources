#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
int pri[100];
LL ans,n;

void prepar(int n)
{
	for (int i=2;i<=sqrt(n);i ++)
	{
		if (n%i==0)
		{
			pri[++ pri[0]] = i;
			while (n%i==0) n /= i;
		}
	}
	if (n>1) pri[++ pri[0]] = n;
}

int main()
{
	freopen("data.in","r",stdin);
	//freopen("1164.out","w",stdout);

	while (scanf("%lld",&n)!=EOF)
	{
		ans = 0;
		prepar(n);
		for (int st=1;st<(1<<pri[0]);st ++) 
		{
			int tot = 0,tmp = 1;
			for (int i=0;i<pri[0];i ++)
				if (st & (1<<i)) tmp *= pri[i+1],tot ++;
			if (tot&1)
				ans += (1+n/tmp)*(n/tmp)/2*tmp;
			else	ans -= (1+n/tmp)*(n/tmp)/2*tmp;
		} 
		ans = (unsigned long long)n*(n+1)/2-ans;
		printf("%lld\n",ans);
	}
	return 0;
}

