#include <cstdio>
using namespace std;

int tot[2],ans[2],n;

int main()
{
	freopen("7-3.in","r",stdin);
	scanf("%d%d",tot,tot+1);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int sum = a+c;
		if ((sum==b && sum==d) || (sum!=b && sum!=d)) continue;
		if (sum==b) tot[0] --,ans[0] ++;
		else tot[1] --,ans[1] ++;
		if (tot[0]<0)
		{
			printf("A\n%d",ans[1]);
			return 0;
		}
		if (tot[1]<0)
		{
			printf("B\n%d",ans[0]);
			return 0;
		}

	}
	return 0;
}
