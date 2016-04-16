#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5+5;

LL l[N];
LL ans;
int last[N],n,k;
int a[N];

int main()
{
	//freopen("drink.in" , "r" , stdin);
	//freopen("drink.out" , "w" , stdout);

	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i ++) l[i] = 1;
	for (int i=1;i<=n;i ++)
	{
		scanf("%d",&a[i]);
		if (a[i]<k) continue;
		if (a[i]>k)
		{
			if (last[a[i]]) l[i]=last[a[i]]+1;
			l[i] = max(l[i],last[0]+1ll);
		}
		if (a[i]==k) last[0] = i;
		int tmp = sqrt(a[i]-k);
		for (int j=1;j<=tmp;j ++)
			if ((a[i]-k)%j==0)
				last[j] = last[(a[i]-k)/j] = i;
	}
	for (int i=1;i<=n;i ++)
		l[i] = max(l[i-1],l[i]), ans+= i-l[i]+1;
	printf("%lld\n",ans);

	return 0;
}
