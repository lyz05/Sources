#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
LL n,m,a,ans;

int main()
{
	freopen("data.in","r",stdin);
	//freopen("mission.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		ans = 0;
		scanf("%lld%lld%lld",&n,&m,&a);
		for (LL x=1;x<=n;x ++)
			if (x*(x-a) % m == 0) ans ++;
		printf("%lld\n",ans);
	}
	return 0;
}

