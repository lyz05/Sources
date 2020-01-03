#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5+2;
const LL oo = 1<<30;
int T,n,a[N];
LL ans;

void dfs(int x,int y,LL sum)
{
	if (x==1)
	{
		while (y!=1)
		{
			sum += a[x];
			y = ceil((double) y/2);
		}
		ans = min(ans , sum);
		return;
	}
	dfs(x-1,y+1,sum);
	while (y!=1)
	{
		y = ceil((double) y/2);
		sum += a[x];
		dfs(x-1,y+1,sum);
	}
}

int main()
{
	freopen("loli.in","r",stdin);
	scanf("%d",&T);
	while (T --)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i ++)
			scanf("%d",a + i);
		for (int i=n-1;i>0;i --)
			a[i] += a[i+1];

		ans = oo;
		dfs(n,1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
