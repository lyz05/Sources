#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 100000, mo = 1e4;
LL x;
int n;
int a[N],w[N][27];

int data(LL &x)
{
	x = (100000005*x + 1532777326) % 998244353;
	return (int)x/100;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	scanf("%d%lld",&n,&x);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d",a + i);
	}
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=26;j ++)
		{
			w[i][j] = data(x) % mo;
		}

	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=26;j ++)
			printf("%d ",w[i][j]);
		puts("");
	}
	return 0;
}
