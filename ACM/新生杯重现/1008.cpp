#include <cstdio>
#include <cstdlib>
#include <cstring>

int n;
long long ans;

int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		ans = 1;
		for (int i=1;i<=n;i ++) ans*=3;
		ans--;
		printf("%lld\n",ans); 
	}
	return 0;
}
