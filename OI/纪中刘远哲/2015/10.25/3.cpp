#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 2000+5,mo = 998244353;
int n;
LL sum,ans,c[N][N];

void prepar()
{
	c[0][0] = 1;
	for (int i=1;i<=n;i ++)
	{
		c[i][0] = 1;
		for (int j=1;j<=i;j ++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mo;
	}
}

int main()
{
	//freopen("mission.in","r",stdin);
	//freopen("mission.out","w",stdout);
	
	scanf("%d",&n);
	//for (n=0;n<=2000;n ++){
	ans = 0;
	prepar();
	for (int i=0;i<=n;i ++)
	{
		sum = 0;
		for (int j=0;j*2<=i;j ++)
		{
			(sum += c[i-j][j]) %= mo;
		}
		(ans += (sum*sum)%mo)%=mo;
	}
	printf("%lld\n",ans);
	//	}
	return 0;
}

