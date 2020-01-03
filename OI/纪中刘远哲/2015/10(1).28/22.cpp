#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100000;
int n;
long long tmp,ans;
int a[N],b[N],c[N];
bool vis[N];

void dfs(int dep)
{
	if (dep>n) 
	{
		if (tmp>ans)
		{
			ans = tmp;
			memcpy(c,b,sizeof b);
		}
		return;
	}
	for (int i=1;i<=n;i ++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			b[dep] = i;
			tmp += a[b[dep]]*a[b[dep-1]];
				dfs(dep+1);
			tmp -= a[b[dep]]*a[b[dep-1]];
			b[dep] = 0;
			vis[i] = 0;
		}
	}
}

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("permutation.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i ++) scanf("%d",a + i);
		tmp = 0;ans = -1;
		dfs(1);
		for (int i=1;i<=n;i ++) printf("%d ",c[i]);
		puts("");
	}

	return 0;
}


