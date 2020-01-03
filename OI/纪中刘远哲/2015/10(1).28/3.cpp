#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int M = 40+5,N = 10+5, mo = 1e9+9,XN=2e6;
int n,m,sum,tmp;
int c[M],a[N];
LL ans,f[XN];

void dfs(int dep)
{
	if (dep>n)
	{
		(ans += f[tmp])%=mo;
		return;
	}
	for (int i=0;i<a[dep];i ++)
	{
		tmp += i;
			dfs(dep+1);
		tmp -= i;
	}
}

int main()
{
	freopen("recursion.in","r",stdin);
	//freopen("recursion.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++) scanf("%d",c+i);
	for (int i=0;i<m;i ++) scanf("%lld",f+i);
	for (int i=1;i<=n;i ++) scanf("%d",a+i),sum+=a[i]-1;

	for (int i=m;i<=sum;i ++) 
		for (int j=1;j<=m;j ++)
			(f[i] += (c[j]*f[i-j])%mo)%=mo;
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
