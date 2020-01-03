#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
LL n,k,tmp;
int a[100];

int main()
{
	freopen("1460.in","r",stdin);
	//freopen("1460.out","w",stdout);

	scanf("%lld",&n);
	k = 0;
	tmp = 1;
	while (tmp<=n/2)
	{
		if (tmp*tmp==n*k+1) a[++ a[0]] = tmp;
		k ++;
		tmp = sqrt(n*k+1);
	}
	for (int i=1;i<=a[0];i ++) printf("%d\n",a[i]);
	for (int i=a[0];i;i --) printf("%lld\n",n-a[i]);
	return 0;
}
