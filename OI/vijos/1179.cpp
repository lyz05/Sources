#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 15;
int n,m,ans,a[N],b[N],f[100*N];

int call(int len)
{
	memset(f,125,sizeof f);
	f[0] = 0;
	int x;
	for (x=0;f[x]<=n;x ++)
	{
		for (int i=1;i<=len;i ++) 
			f[x+a[i]] = min(f[x+a[i]],f[x]+1);
	}
	return x-1;
}

void dfs(int x)
{
	if (x>m)
	{
		int now = call(x-1);
		if (now>ans) 
		{
			ans = now;
			memcpy(b,a,sizeof a);
		}
		return;
	}
	for (int i=call(x-1)+1;i>=a[x-1];i--)
	{
		a[x] = i;
		dfs(x+1);
		a[x] = 0;
	}
}

int main()
{
	freopen("1179.in","r",stdin);
	//freopen("1179.out","w",stdout);

	scanf("%d%d",&n,&m);
	dfs(1);
	for (int i=1;i<=m;i ++) printf("%d ",b[i]);
	puts("");
	printf("MAX=%d\n",ans);
	return 0;
}
