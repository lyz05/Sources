#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 1000+5;
int n,tot;
int a[N],pri[N];
LL f[2][N],ans;
bool p[N];

void prepar(int n)
{
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
	f[0][0] = 1;
	int p=1;
	for (int i=1;i<=tot;i ++,p^=1)
	{
		memcpy(f[p],f[p^1],sizeof f[p]);
		for (int j=pri[i];j<=n;j*=pri[i])
		{
			for (int k=0;k+j<=n;k ++)
				f[p][k+j] += f[p^1][k];
		}
	}
	for (int i=0;i<=n;i ++) ans += f[p^1][i];
}

int main()
{
	freopen("1038.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&n);
	prepar(n);
	dp();
	printf("%lld\n",ans);
	return 0;
}

