#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int mo = 54187;
int n,tmp,ans;

int main()
{
	freopen("tri.in","r",stdin);
	freopen("tri.out","w",stdout);
	
	ans = 1;
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
	{
		scanf("%d",&tmp);
		if (i>j && tmp!=0) 
		{
			puts("No");
			return 0;
		}
		if (i==j) 
			(ans *= tmp) %= mo;
	}
	printf("%d\n",ans);

	return 0;
}
