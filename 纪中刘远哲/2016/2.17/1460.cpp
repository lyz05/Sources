#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
LL n;

int main()
{
	freopen("1460.in","r",stdin);
	//freopen("1460.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		LL tmp = (LL)i*i;
		if (tmp%n==1) printf("%d\n",i);
	}

	return 0;
}
