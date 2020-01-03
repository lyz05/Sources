#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100000+5;
int n,ans,tmp,i,now;
int a[N];

int main()
{
	freopen("1845.in","r",stdin);
	//freopen("1845.out","w",stdout);

	scanf("%d",&n);
	for (i=1;i<=n;i ++) scanf("%d",&a[i]);
	for (i=1,tmp = 1,now = 0;i<n;i ++)
		if ((now && a[i]<a[i+1]) || (!now && a[i]>a[i+1]))
		{
			tmp ++;
			now ^= 1;
		}
	ans = tmp;
	for (i=1,tmp = 1,now = 1;i<n;i ++)
		if ((now && a[i]<a[i+1]) || (!now && a[i]>a[i+1]))
		{
			tmp ++;
			now ^= 1;
		}
	ans = max(ans,tmp);
	printf("%d\n",ans);
	return 0;
}
