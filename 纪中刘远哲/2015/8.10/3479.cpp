#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 50000;
int n,k,c,a[N];
long long f[N];

int main()
{
	freopen("3479.in","r",stdin);

	scanf("%d%d%d",&n,&k,&c);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d",&a[i]);

	}
	sort(a + 1,a + 1 + n);
	memset(f,124,sizeof f);
	f[0] = 0;
	for (int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; i-j+1 >= k; j ++)
		{
			f[i] = min(f[i] ,f[j-1]+(a[i]-a[j])*(a[i]-a[j])+c);
		}

	printf("%lld\n",f[n]);
	return 0;
}
