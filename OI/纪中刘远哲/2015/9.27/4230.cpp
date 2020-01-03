#include <cstdio>
#include <algorithm>
#include <cstring>

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	for (int i=1;i<=n;i ++) scanf("%d",b + i);
	double l = 1, r = 1000;
	while (l<r)
	{
		double mid = (l+r)/2;
		if judge(mid) 
		{
			ans = mid;
			mid = l+1;
		} else r = mid-1;
	}
	printf("%.3lf\n",ans);
	return 0;
}
