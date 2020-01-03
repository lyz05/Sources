#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 10000+5,K=100+5;
typedef long long LL;
int n,k,a,b,c,mo;
LL A[N],ans;

void dfs(int dep,int cnt,LL tmp)
{
	if (dep>n)
	{
		if (cnt==k) 
		{
			(ans += tmp) %= mo;
		}
		return;
	}
	for (int i=0;i<=1;i ++)
	{
		if (i % 2==0)
		{
			dfs(dep+1,cnt+1,tmp*A[dep]);
		}
		else	dfs(dep+1,cnt,tmp);
	}
}

int main()
{
	freopen("data.in","r",stdin);
	//freopen("flower.out","w",stdout);

	scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&mo);
	a %= mo,b %= mo,c %= mo;
	for (int i=1;i<=n;i ++)
	{
		A[i] = (i*(LL)floor(a*log(i+b)+c)%mo)%mo;
	}
	//tmp = 1;
	dfs(1,0,1);
	printf("%lld\n",ans);
	return 0;
}

