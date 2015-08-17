#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 50000;
int n,l;
LL c[N],g[N],f[N];

LL sqr(LL x)
{
	return x*x;
}

int main()
{
	freopen("1116.in","r",stdin);
	
	scanf("%d%d",&n,&l);
	g[0] = 0;
	for (int i = 1 ; i <= n ; i ++)
	{
		scanf("%lld",&c[i]);
		g[i] = g[i-1] + c[i] + 1;
	}
	memset(f,124,sizeof(f));
	f[0] = 0;
	for (int i = 1 ; i<= n ; i++)
	{
		for (int j = i-1 ; j >= 0 ; j --)
		{
			f[i] = min(f[i],f[j]+sqr(g[i]-g[j]-l-1));
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}

