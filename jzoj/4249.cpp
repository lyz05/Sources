#include <cstdio>
using namespace std;

const int N = 100000+5;
int n,a[N],ans;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a+i);

	int maxx = 0;
	for (int i=n;i>=1;i--)
	{
		if (a[i]>maxx) maxx = a[i];
		a[i] = maxx;
		ans += a[i];
	}
	printf("%d\n",ans);
}
