#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 10000+5;
int n,tot,T;
int a[N],pri[N];
long double f[2][N];
int g[1500][N];

bool p[N];

void prepar(int n)
{
	memset(p,0,sizeof p);
	tot = 0;
	for (int i=2;i<=n;i ++)
	{
		if (!p[i])
		{
			pri[++ tot] = i;
			for (int j=2;i*j<=n;j ++)
				p[i*j] = 1;
		}
	}
}

void dp()
{
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	f[0][0] = log(1);
	//g[0][0][0] = g[0][0][1] = 1;
	int p=1;
	for (int i=1;i<=tot;i ++,p^=1)
	{
		memcpy(f[p],f[p^1],sizeof f[p]);
		//memcpy(g[i],g[i-1],sizeof g[i]);
		for (int j=pri[i];j<=n;j*=pri[i])
		{
			for (int k=0;k+j<=n;k ++)
				if (f[p^1][k]+log(j)>f[p][k+j])
				{
					f[p][k+j] = f[p^1][k]+log(j);
					g[i][k+j] = j;
				}
		}
	}
	long double maxx = 0;
	int now = p^1,id = 0;
	for (int i=n;i;i --) 
		if (f[now][i]>maxx)
		{
			maxx = f[now][i];
			id = i;
		}

		if (f[now][id]) 
		{
			int sum = id;
			for (int i=tot;i;i --) a[i] = g[i][id],id -= g[i][id];
			sort(a+1,a+1+tot);
			
			sum = sum-id;
			for (int j=1;j<=n-sum;j ++) printf("%d ",j);
			sum = n-sum;
			for (int i=1;i<=tot;i ++) 
				if (a[i])  
				{
					for (int k=1;k<a[i];k ++)
						printf("%d ",sum+k+1);
					printf("%d ",sum+1);
					sum += a[i];
				}
			puts("");
		
			
		}
	//for (int i=0;i<=n;i ++) ans += f[p^1][i];
}


int main()
{
	freopen("3232.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n==1) printf("1\n");else 
		{
			prepar(n);
			dp();
		}
	}
	return 0;
}


