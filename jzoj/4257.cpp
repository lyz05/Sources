#include <cstdio>
#include <algorithm>

typedef long long LL;
const int a[8][2]={{2,1572858},{0,96},{2,18},{2,24576-6},{0,12},{0,6},{0,96},{2,1073741826-6}};
int n,k;

int main()
{
	//freopen("color.in","r",stdin);
	//freopen("color.out","w",stdout);

	scanf("%d%d",&n,&k);
	int x = k*(k-1)/2,y = k*(k-1)*(k-2)/6;
	LL ans = (LL)x*a[n-1][0]+(LL)y*a[n-1][1];
	printf("%lld\n",ans);
	return 0;
}
