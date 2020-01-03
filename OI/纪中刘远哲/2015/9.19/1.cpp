#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 100000+5;
int a[N],n,m,k,maxx = 0;
LL ans = 0,sum = 0;

int main()
{
	freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[u] ++;a[v] ++;
	}
	for (int i=1;i<=n;i ++)
	{	
		a[i] = k-a[i];
		if (a[i]>0)
		{
			sum += a[i];
			if (a[i]>maxx) maxx = a[i];
		}
	}
	if (maxx>sum-maxx) printf("%d\n",maxx);
	else {
		ans = ceil((double)sum/2);
		printf("%I64d\n",ans);
	}
	return 0;
}
