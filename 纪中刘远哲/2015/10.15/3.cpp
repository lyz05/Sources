#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000+5;
int n,a[N],f[N],g[N];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d\n",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);

	for (int i=1;i<=n;i ++)
	{
		for (int j=0;j<=i-1;j ++)
		{
			f[i] = max(f[i],f[j]+(i-j)*a[i]);
		}
		g[i] = f[i]-f[i-1];
	}
	printf("%d\n",f[n]);
	return 0;
}
