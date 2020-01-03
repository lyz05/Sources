#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
int n;
LL ans;

int gcd(int x,int y)
{
	if (y==0) return x;
	else return gcd(y,x%y);
}

int main()
{
	//freopen("1164.in","r",stdin);
	//freopen("1164.out","w",stdout);

	while (scanf("%d",&n)!=EOF)
	{
		ans = 0;
		for (int i=1;i<=n;i ++) 
			if (gcd(i,n)==1) 
				ans += (LL)i;
		printf("%lld\n",ans);
	}
	return 0;
}
