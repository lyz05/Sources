#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int N = 20,M = 25,INF = 2139062144;
int n,m,ans;
int a[N],b[N],f[2][(1<<14)+5];
vector <int> Q[M];

void init()
{
	for (int i=1;i<=n;i ++) scanf("%d %d",&a[i],&b[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i ++) 
	{
		int x,tot;
		Q[i].clear();
		scanf("%d",&tot);
		for (int j=0;j<=tot;j ++) 
			scanf("%d",&x),Q[i].push_back(x);
	}
}

void work()
{
	ans = 0;
	memset(f,128,sizeof f);
	f[0][0] = 0;
	bool flag = 1;
	for (int i=1,p=1,q=0;i<=n;i ++,p^=1,q^=1)
	{
		memset(f[p],128,sizeof f[p]);
		flag = 0;
		for (int s=0;s<(1<<n);s ++)
		{
			for (int j=1;j<=m;j ++)
			{
				bool ok = 1;
				int tmp = 0,val = 0;
				for (int k=1;k<Q[j].size() && ok;k ++) 
    					tmp += (1<<(Q[j][k]-1)),ok = a[Q[j][k]]>0,val += a[Q[j][k]];
				if ((tmp & s)==tmp && ok && f[q][s-tmp]!=-INF) 
				{
					flag = 1;
					f[p][s] = max(f[p][s],f[q][s-tmp] + (Q[j][0] + val));
					ans = max(ans,f[p][s]);
				}
			}
		}
		for (int j=1;j<=n;j ++) a[j] -= b[j];
	}
}

int main()
{
	freopen("1040.in","r",stdin);
	//freopen("1040.out","w",stdout);

	while (scanf("%d",&n),n)
	{
		init();
		work();
		printf("%d\n",ans);
	}

	return 0;
}
