#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 3000000;
int n,a[N];

int main()
{
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	
	for (int i=1;i<=n;i ++)
	{
		int j = 1,k = 1;
		while (a[i-(j+1)+1]<a[i] && i-(j+1)+1>=1) j ++;
		while (a[i+(k+1)-1]<=a[i] && i+(k+1)-1<=n) k ++;
		printf("%lld\n",(LL)j*k);
	}

	return 0;
}
