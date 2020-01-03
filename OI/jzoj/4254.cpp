#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int A = 50,S = 1500, N = 55,mo = 1e9+7;
int n,fac;
int a[N];
LL sum[N],Fac[A+5],c[S+5][S+5],f[N][S+5];

void prepar()
{
	Fac[1]=1;
	for (int i=2;i<=A;i ++) Fac[i] = (Fac[i-1]*i)%mo;
	fac = 1;
	for (int i=1;i<=n;i ++) fac = fac*Fac[a[i]]%mo;

	c[0][0]=1;
	for (int i=1;i<=S;i ++)
	{
		c[i][0] = 1;
		for (int j=1;j<=i;j ++)
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%mo;
	}
}

int main()
{
	freopen("photo.in","r",stdin);
	//freopen("photo.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a+i) , sum[i] = sum[i-1] + a[i];
	
	//sum[0]=1;
	prepar();
	f[1][a[1]-1] = 1;
	for (int i=2;i<=n;i ++)
	for (int j=0;j<=sum[i-1]-1;j ++)
	for (int k=1;k<=a[i];k ++)
	for (int t=0;t<=min(k,j);t ++)
	{
		(f[i][j+a[i]-k-t] += (((f[i-1][j]*c[j][t])%mo*c[a[i]-1][k-1])%mo
				*c[sum[i-1]+1-j][k-t])%mo)%=mo;
	}
	printf("%lld\n",f[n][0]*fac%mo);
	return 0;
}
