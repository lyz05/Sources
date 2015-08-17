#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 200005, M = N, W = 1e6;
int n,m;
LL st,w[N],v[N],x[M],y[M],sum[N],s[N];
LL ans=(LL)1<<62;
LL maxw;

bool judge(LL ww)
{
	s[0]=sum[0]=0;
	for (int i=1;i<=n;i++) 
	{
		s[i] = s[i-1];
		sum[i] = sum[i-1];
		if (w[i]>=ww)
		{
			s[i] ++;
			sum[i] += v[i];
		}
	}
	LL tot=0;
	for (int i=1;i<=m;i++)
	{
		//x[i] y[i]
		tot += (sum[y[i]]-sum[x[i]-1])*(s[y[i]]-s[x[i]-1]);
	}
	ans = min(ans,abs(st-tot));
	if (tot>=st) return 1; else return 0;
}

int main()
{
	freopen("1740.in","r",stdin);
	scanf("%d%d%lld",&n,&m,&st);
	for (int i=1; i<=n ; i++) scanf("%lld%lld",w+i,v+i),maxw=max(maxw,w[i]);
	for (int i=1; i<=m ; i++) scanf("%lld%lld",x+i,y+i);
	
	LL l=0,r=maxw,mid;
	while (l<=r)
	{
		mid = (l+r)>>1;
		if (judge(mid)) l=mid+1; else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}
