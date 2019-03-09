#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,ans[2];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int t;
		scanf("%d",&t);
		if (t%2) ans[0] ++;else ans[1] ++;
	}
	printf("%d %d\n",ans[0],ans[1]);
	return 0;
} 
