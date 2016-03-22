#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200000+5, INF = 1e9+7;
int n,ctot,ans;
int a[N],col[N],dep[N];

int work(int x)
{
	int deep = 0;
	while (col[x]==0)
	{
		col[x] = ctot;
		dep[x] = ++ deep;
		x = a[x];
	}
	if (col[x]==ctot) return deep-dep[x]+1;
	return INF;
}

int main()
{
	freopen("message.in","r",stdin);
	//freopen("message.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a+i);
	
	ctot = 0;ans = INF;
	for (int i=1;i<=n;i ++)
		if (!col[i]) ctot ++,ans = min(work(i),ans);
	printf("%d\n",ans);

	return 0;
}

