#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,a[(1<<20)+5],ans;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++)
	{
		int t,now = 0;
		for (int j=1;j<=m;j ++) 
		{
			scanf("%d",&t);
			now = (now << 1)+t;
		}
		a[now] ++;
	}
	int L = 0,R = (1<<m)-1;
	for (int i=L;i<=R;i ++)
	{
		ans += a[i]*a[i^R];
	}
	printf("%d\n",ans/2);
	return 0;	
} 
//1 1 2 3 5 8 13
