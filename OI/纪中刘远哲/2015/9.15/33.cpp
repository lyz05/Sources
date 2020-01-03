#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>
using namespace std;

int n,m,k,now;
list <int> lis;

int main()
{
	freopen("data.in","r",stdin);
	freopen("33.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		int ans = 1 ,ret = 2;
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=n;i ++)
		{
			ans = (ans * 2) % k;
			if (i==m) ans -= ret;
			if (i>m)
			{
				ans -= ret;
				ret = (ret * 2) % k;
			}
			/*
			if (ans>=k)
			{
				ans = k;
				break;
			}
			*/
		}
		printf("%d\n",ans);
	
	}
	return 0;
}

