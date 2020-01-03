#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1002, M = 10002;
int n,m,k,d[N],a[M],b[M],t[M];
int arv[N],last[N],sum[N],next[N];
int ans,tot;

void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1 ; i < n ; i ++) scanf("%d",&d[i]);
	for (int i = 1 ; i <= m ; i ++)
	{
		scanf("%d%d%d",&t[i],&a[i],&b[i]);
		last[a[i]] = max(last[a[i]],t[i]);
		sum[b[i]] ++;
	}
	for (int i = 2 ; i <= n ; i ++)
	{
		arv[i] = max(arv[i-1],last[i-1]) + d[i-1];
		sum[i] += sum[i-1];			//统计一下车人数
	}
	next[n] = n;next[n-1] = n;
	for (int i = n-2 ; i > 0; i --)
	{
		if (arv[i+1]>last[i+1]) next[i] = next[i+1];//两类人可以加速
		else next[i] = i+1;
	}
	for (int i = 1; i <= m ; i ++)
		ans += arv[b[i]] - t[i];
}

void work()
{
	int maxs = 0, l , r;
	for (int i=1 ; i <= n-1 ; i ++)//找寻放氮气的最大人数区间
	{
		if (maxs<sum[next[i]]-sum[i] && d[i]>0)
		{
			maxs = sum[next[i]]-sum[i]; l = i; r = next[i];
		}
	}
	tot += maxs;//消耗一个氮气，缩短区间内所有人的等待时间
	d[l] -- ;
	if (r == n) r --;
	for (int i = l+1 ; i <= r; i ++) arv[i]=max(arv[i-1],last[i-1])+d[i-1];
	for (int i=r;i>=l;i--)
	{
		if (arv[i+1]>last[i+1]) next[i] = next[i+1];
		else next[i] = i+1;
	}
}

int main()
{
	freopen("1741.in","r",stdin);

	init();
	while (k--) work();
	printf("%d\n",ans-tot);

	return 0;
}
