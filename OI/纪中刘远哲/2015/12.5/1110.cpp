#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

typedef long long LL;
const int N = 12,mo = 1e9+7;
int n;
int a[N],tmp[N];
LL ans;
map <LL,LL> p[N];

LL dfs(LL now);

LL calc(LL p,LL lim,LL now)
{
	if (p>n)
	{
		if (lim==0) return dfs(now+1);
		else return 0;
	}
	if (3*(n-p+1)<lim) return 0;
	LL ret = 0;
	if (a[p]>=3)
	{
		a[p] -= 3;
			(ret += calc(p+1,lim,now))%=mo;
		a[p] += 3;
	}
	if (a[p] && lim)
	{
		a[p] --;
			(ret += calc(p+1,lim-1,now))%=mo;
		a[p] ++;
	}
	if (lim>=3) (ret += calc(p+1,lim-3,now))%=mo;
	return ret;	
}

LL dfs(LL now)
{
	if (now==n)
	{
		if (a[n]==0) return 1;
		else return 0;
	}
	tmp[0]=0;
	for (int i=now;i<=n;i ++) tmp[++ tmp[0]] = a[i];
	sort(tmp+1,tmp+tmp[0]+1);
	LL ha = 0;
	for (int i=1;i<=tmp[0];i ++) ha=ha*28+tmp[i];
	if (p[now].find(ha)!=p[now].end()) return p[now][ha];
	return p[now][ha] = calc(now+1,a[now],now);
}

int main()
{
	freopen("1110.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	sort(a+1,a+1+n);
	ans = dfs(1);
	printf("%lld\n",ans);
	return 0;
}
