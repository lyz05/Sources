#include <cstdio>

using namespace std;

const int K=1000+10,mo=10007;

int a,b,n,m,k;
long long f[K][K];

int main()
{
	scanf("%d%d%D%D%D",&a,&b,&k,&n,&m);
	a%=mo;b%=mo;
	k++;
	f[1][1]=1;
	for (int i=2;i<=k;i++)
		for (int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j]+f[i-1][j-1])%mo;
	long long ans=1;
	for (int i=1;i<=n;i++) ans=(ans*a)%mo;
	for (int i=1;i<=m;i++) ans=(ans*b)%mo;
	ans*=f[k][m+1];
	ans%=mo;
	printf("%d\n",ans);
	return 0;
}
