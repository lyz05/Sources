#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1e6+5,M = N;
int n,m,s[N],x[M],y[M],d[M],a[N];

bool judge(int limit)
{
	memset(s,0,sizeof s);
	int sum = 0;
	for (int i=1;i<=limit;i ++)
		s[x[i]] += d[i],s[y[i]+1] -= d[i];
	for (int i=1;i<=n;i ++)
	{
		sum += s[i];
		if (sum>a[i]) return 0;
	}
	return 1;
}

int main()
{
	freopen("1782.in","r",stdin);
	//freopen("1782.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	for (int i=1;i<=m;i ++) scanf("%d%d%d",d+i,x+i,y+i);
	
	int l = 1,r = n,mid = (l+r)>>1,ans = 0;
	while (l<=r)
	{
		mid = (l+r)>>1;
		if (!judge(mid))
		{
			ans = mid;
			r = mid - 1;	
		} else l = mid + 1;
	}
	if (!ans) printf("0\n");else printf("-1\n%d\n",ans);

	return 0;
}
