#include <cstdio>
using namespace std;

const int N = 300005,mo = 1E9 + 7;
typedef int one [N];
typedef long long LL;
int n,m,k;
LL fac[N];
one t,num,count,g;
LL power(int a, int b)
{
	if (!b) return 1;
	LL mid=power(a,b / 2);
	if (b & 1) return mid*mid%mo*a%mo;
	return mid*mid%mo;
}

LL C(int n,int m)
{
	if (n==m || m==0) return 1;
	return fac[n] * power(fac[m] * fac[n-m] % mo , mo - 2) % mo;
}

int main()
{
	freopen("3489.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	fac[0] = 1;
	for (int i = 1 ; i <= n ;i ++)
		fac[i] = fac[i-1] * i % mo;
	for (int i = 1; i <= n ; i ++)
		scanf("%d",&t[i]) ,count[t[i]] ++;
	for (int i = 1; i <= m ; i ++)
		for (int j = 1 ; j <= m/i ; j ++)
			num[i] += count[i * j];
	for (int i = 1;i <= m;i ++)
	{
		LL d;
		d = num[i];
		if (d < n-k) g[i] = 0;else 
		{
			int h = m/i,least = d - (n - k);
			g[i] = C(d,n-k)*power(h-1,least)%mo*power(h,n-d)%mo;
		}
	}
	for (int i = m ; i >= 1 ; i --)
		for (int j = 2 ; j <= m/i ; j ++)
			g[i] = (g[i]-g[i*j]+mo) % mo;
	for (int i=1 ; i <= m ; i ++)
		printf("%d ",g[i]);
	printf("\n");
}
