#include<cstdio>
#include<algorithm>
using namespace std;

int n,ans=1;

int main()
{
	//freopen("0.in","r",stdin);
	scanf("%d",&n);
	for (int m=1;m<=n;m ++)
	{
		int t=m;
		while (t!=1)
		{
			ans=max(ans,t);
			if (t%2) t = t*3+1;else t >>= 1;
			//printf("%d\n",t);
		}
		//printf("\n");
	}
	printf("%d\n",ans);
	return 0;
} 