#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1005,K = 10005;
typedef long long LL;
int n,k,p;
int a[N][N],ans[N],Last[N];
LL sum[2][K],f[N][K];
bool b[N];

int main()
{
	freopen("ocd.in","r",stdin);
	//freopen("ocd.out","w",stdout);

	scanf("%d%d%d",&n,&k,&p);
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=n;j ++) 
			scanf("%d",&a[i][j]);
		Last[i] = i-1;
	}

	f[0][0] = f[1][0] = 1;
	for (int i=0;i<=k;i ++) sum[1][i] = 1;
	for (int i=2,now = 0,last = 1;i<=n;i ++,now ^= 1,last ^= 1) 
	{
		memset(sum[now],0,sizeof sum[now]);
		sum[now][0] = f[i][0] = 1;
		for (int j=1;j<=k;j ++)
		{
			if (j-i>=0) f[i][j] = sum[last][j]-sum[last][j-i];
			else f[i][j] = sum[last][j];
			if (f[i][j]>p) f[i][j] = p+1;
			sum[now][j] = sum[now][j-1] + f[i][j];
		}
	}

	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=n;j ++)
			if (!b[a[i][j]])
			{
				int now = a[i][j];
				if (p-f[n-i][k-Last[now]]>0)
				       	p -= f[n-i][k-Last[now]];
				else
				{
					ans[i] = now;
					b[now] = 1;
					k -= Last[now];
					break;
				}
			}
		for (int j=ans[i]+1;j<=n;j ++)
					Last[j] --;
	}
	for (int i=1;i<=n;i ++) if (ans[i]==0)
	{
		puts("-1");
		return 0;
	}
	for (int i=1;i<=n;i ++) printf("%d ",ans[i]);
	return 0;
}
