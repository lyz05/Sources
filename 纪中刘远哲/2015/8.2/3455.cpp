#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1000 + 5;
int n,a[N],b[N];

bool cmp(int x,int y)
{
	if (x>y) return 1;else return 0;
}

int main()
{
	freopen("3455.in","r",stdin);

	scanf("%d",&n);
	for (int i = 1;i <= n;i ++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i ++) scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n,cmp);
	long long ans = 0;
	for (int i = 1;i <= n; i ++)
	{
		ans += (long long) a[i]*(long long) b[i];
	}
	printf("%lld",ans);
	return 0;
}
