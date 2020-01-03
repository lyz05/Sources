#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 1e7+5,mo=1e9+7;
int l,r,a;
LL ans;

bool judge(int x)
{
	if (x%a==0) return 0;
	int tot = 0;
	while (x)
	{
		int y = x % 10;
		x = x/10;
		tot += y;
		if (y==a) return 0;
	}
	if (tot%a == 0) return 0;
	return 1;
}

int main()
{
	freopen("bachelor.in","r",stdin);
	//freopen("bachelor.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		ans = 0;
		scanf("%d%d%d",&l,&r,&a);
		for (int i=l;i<=r;i ++)
		{
			if (judge(i)) (ans += ((LL)i*i)%mo) %= mo;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
