#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 1000000+2;
int n,a,b,c,s[N];
LL f[N];

LL work(LL x)
{
	return (x*x*a+x*b+c);
}

int main()
{
	//freopen("2318.in","r",stdin);
	
	scanf	("%d\n%d%d%d",&n,&a,&b,&c);
	s[0] = 0;
	for (int i = 1; i <= n ; i ++)
	{
		int x;
		scanf("%d",&x);
		s[i] = s[i-1] + x;
	}
	f[0] = 0;
	for (int i = 1 ; i <= n ; i ++)
	{
		for (int j = i-1 ; j	>= 0 ; j --)
		{
			f[i] = max(f[i],f[j]+work(s[i]-s[j]));
		}
	}
	printf("%lld\n",f[n]);

	return 0;
}
