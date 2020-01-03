#include <cstdio>
using namespace std;

int n;

int main()
{
	for(scanf("%d",&n);n!=0;scanf("%d",&n))
	{
		int now = 0,ans = 0;
		for (int i=1;i<=n;i ++) 
		{
			int t;
			scanf("%d",&t);
			if (t - now>0) ans += 6*(t - now);else ans += 4*(now-t);
			now = t;
		}
		ans += 5*n;
		printf("%d\n",ans);
	}
	
	return 0;
 } 
