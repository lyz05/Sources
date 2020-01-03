#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 20;
int vis[N],a[N][N],n,l,tmp,ans;

void dfs(int dep,int x)
{
	if (tmp>l) return;
	if (dep==n+1)
	{
		if (x==1 && vis[x] && tmp==l) 
			ans ++;
		return;
	}
	if (x==1 && vis[x]) return;

	for (int i=1;i<=n;i ++)
	{
		if (!vis[i])
		{
			tmp += a[x][i];
			vis[i] = 1;
				dfs(dep+1,i);
			vis[i] = 0;
			tmp -= a[x][i];
		}
	}
}

int main()
{
	freopen("way.in","r",stdin);
	//freopen("way.out","w",stdout);
	
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=n;j ++) scanf("%d",&a[i][j]);

	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}

