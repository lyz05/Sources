#include <cstdio>
#include <algorithm>

typedef long long LL;
const int N = 300000+5, M = 100000;
int n,k,a[N];
LL ans;
double s[N];

bool judge(double x)
{
	double minn = N;
	int j = 0;
	for (int i=1;i<=n;i ++)
	{
		s[i] = s[i-1] + ((double)a[i]-x);
		while (j<i-k) {j ++; minn = (minn>s[j])?s[j]:minn;}
		if (i>=k && s[i] - minn>=0) return 1;
	}
	return 0;
}

int main()
{
	freopen("average.in","r",stdin);
	//freopen("average.out","w",stdout);

	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	
	LL l = 0, r = (LL)1000000*M;
	while (l<r)
	{
		LL mid = (l+r)>>1;
		if (judge((double)mid/M))
		{
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}

	printf("%.6f\n",(double)ans/M);
	return 0;
}
