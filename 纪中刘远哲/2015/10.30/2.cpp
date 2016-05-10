#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 10000+5,K=100+5;
typedef long long LL;
int n,k,a,b,c,mo;
LL F[N][K],A[N];

int main()
{
	//freopen("flower.in","r",stdin);
	//freopen("flower.out","w",stdout);

	scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&mo);
	a %= mo,b %= mo,c %= mo;
	for (int i=1;i<=n;i ++)
	{
		A[i] = (i*(LL)floor(a*log(i+b)+c)%mo)%mo;
	}
	
	for (int i=0;i<=n;i ++) F[i][0] = 1;
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=min(k,i);j ++)
			F[i][j] = ((F[i-1][j-1]*A[i])%mo + F[i-1][j])%mo;
	printf("%lld\n",F[n][k]);
	return 0;
}

