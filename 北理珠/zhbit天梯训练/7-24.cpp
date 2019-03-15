#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1e5+7;
int n,a[N],tot1,tot2,sum,sum1,sum2;

bool cmp(int x,int y)
{
	return x<y;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	tot1 = n/2;
	tot2 = n - tot1;
	//for (int i=1;i<=n;i ++)
	//	printf("%d ",a[i]);
	for (int i=1;i<=n;i ++)
	{
		if (i<=tot1) sum1 += a[i];
		else sum2 += a[i];
	}
	printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d",tot2,tot1,sum2-sum1);
	return 0;
} 
