#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 20;
int ans,n,w;
int f[N],a[N];

bool cmp(int x,int y) {return x>y;}

bool dfs(int x)
{
	if (x>n) return 1;
	for (int i=1;i<=x && i<=ans;i ++)
		if (f[i]+a[x]<=w)
		{
			f[i] += a[x];
			if (dfs(x+1)) return 1;
			f[i] -= a[x];
		}
	return 0;
}

int main()
{
	//freopen("3394.in","r",stdin);
	//freopen("3394.out","w",stdout);

	scanf("%d%d",&n,&w);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	sort(a+1,a+1+n,cmp);

	for (ans=1;ans<=n;ans ++)
	{
		memset(f,0,sizeof f);
		if (dfs(1)) break;
	}
	printf("%d\n",ans);

	return 0;
}
