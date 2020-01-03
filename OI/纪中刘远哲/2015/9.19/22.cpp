#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long long LL;
const int N = 100000+5, mo = 1e4;
LL x;
int n;
int a[N],w[N][27],rank[N];
LL f[N][27],ans;

int data(LL &x)
{
	x = (100000005*x + 1532777326) % 998244353;
	return (int)x/100;
}

void init()
{
	scanf("%d%I64d",&n,&x);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d",a + i);
	}
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=26;j ++)
		{
			w[i][j] = data(x) % mo;
		}
	for (int i=1;i<=n;i ++) rank[a[i]] = i;
}

bool judge(int i)
{
	return rank[a[i]+1]>rank[a[i-1]+1];
}

void work()
{
	for (int i=1;i<=26;i ++) f[1][i] = w[a[1]][i];
	for (int i=2;i<=n;i ++)
		for (int j=1;j<=26;j ++)
		{
			for (int k=1;k<=j;k++)
			{
				if (k==j && !judge(i)) continue;
				f[i][j] = max(f[i][j] , f[i-1][k]+w[a[i]][j]);
			}
		}
	ans = 0;
	for (int i=1;i<=26;i ++)
		ans = max(ans, f[n][i]);
	printf("%I64d\n",ans);
}

int main()
{
	freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	
	init();
	work();

	return 0;
}
