#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 3000+5;
const LL mo = 10000000007;
int n,k,now,last;
LL f[2][N],sum[2][N];

int main()
{
	freopen("matryoshka.in","r",stdin);
	freopen("matryoshka.out","w",stdout);

	scanf("%d%d",&n,&k);

	for (int i=0;i<=k;i ++) sum[1][i] = 1;
	f[0][0] = f[1][0] = 1;
	now = 0,last = 1;
	for (int i=2;i<=n;i ++,now^=1,last^=1)
	{
		memset(sum[now],0,sizeof sum[now]);
		f[now][0] = sum[now][0] = 1;
		for (int j = 1;j<=k;j ++)
		{
			f[now][j] = (j-i>=0)?
				(sum[last][j]-sum[last][j-i]+mo)%mo:
				sum[last][j];
			sum[now][j] = (sum[now][j-1]+f[now][j])%mo;
		}
	}
	printf("%lld\n",sum[last][k]);

	return 0;
}

