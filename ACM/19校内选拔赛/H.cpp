#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000+5;
int a[N],sum[N]; 
int n,m,ans;

int main()
{
	while (~scanf("%d %d",&n,&m))
	{
		for (int i=1;i<=n;i ++)	scanf("%d",a + i);
		sort(a+1,a+1+n);
		sum[0] = 0;ans = 1e9+7;
		for (int i=1;i<=n;i ++) sum[i] = sum[i-1] + a[i];
		for (int i=m;i<=n;i ++)
		{
			int tmp = (a[i]*m)-(sum[i]-sum[i-m]);
			ans = min(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}
