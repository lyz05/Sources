#include <cstdio>

using namespace std;

int n,m,x,k;
long long ans;

long long mult(int y)
{
	if (y==0) return 1;
	if (y==1) return 10 % n;
	if (y%2==1) return (((mult(y>>1)*mult(y>>1))%n)*10)%n;
	else return (mult(y>>1)*mult(y>>1)%n);
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&x);
	ans=mult(k);
	ans*=m;ans%=n;ans+=x;ans%=n;
	printf("%lld\n",ans);
	return 0;
}
