#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
int n;

int main()
{
	freopen("data.in","r",stdin);
	freopen("1460.out","w",stdout);

	while (scanf("%d",&n)!=EOF)
	{
		//printf("%d\n",n);
		for (int i=1;i<=n;i ++)
		{
			LL tmp = i*i;
			if (tmp%n==1) printf("%d ",i);
		}
		puts("");
	}
	return 0;
}
