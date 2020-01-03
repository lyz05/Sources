#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 2048+5;
int n,K,a[N],vis[N],ans[N];

bool dfs(int x,int dep)
{
	if (vis[x]) return 0;
	if (dep==n) 
		return 1;
	ans[dep] = x&1;
	vis[x] = 1;
	if (dfs((x<<1)&(n-1),dep+1)) return 1;
	if (dfs((x<<1|1)&(n-1),dep+1)) return 1;
	vis[x] = 0;
	ans[dep] = 0;
	return 0;
}

int main()
{
	//freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);

	scanf("%d",&K);
	n = (1<<K);
	dfs(0,1);
	printf("%d ",n);
	for (int i=1;i<K;i ++) printf("0");
	for (int i=1;i<=n-K+1;i ++) printf("%d",ans[i]);
	puts("");
	return 0;
}
