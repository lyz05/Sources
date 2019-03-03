#include <cstdio>
#include <algorithm>
using namespace std;

int n,minn=1e9+7,maxx=-1e9+7,sum = 0;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int t;
		scanf("%d",&t);
		minn = min(t,minn);
		maxx = max(t,maxx);
		sum += t;
	}
	printf("%d\n%d\n%d\n",maxx,minn,sum);
	return 0;	
} 
//1 1 2 3 5 8 13
