#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int gf(int x)
{
	return (x==fa[x])?x:fa[x]=gf(fa[x]);
}

void dfs(int x,int id)
{
	vis[x] = 1;
	for (int i=e[x];i;i=h[i].next)
	{
		if (h[i].id==id) continue;
		if (!vis[h[i].y]) dfs(h[i].y,id);
	}
}

int work()
{
	int ans = 0;
	for (int i=1;i<=id;i ++)
	{
		memset(vis,0,sizeof vis);
		dfs(1,i);
		for (int i=1;i<=n;i ++)
			if (!vis[i]) ans ++;
	}
	return ans;
}

int main()
{
	//freopen("mission.in","r",stdin);
	//freopen("mission.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)	
	{
		int x,y;
		id ++;
		scanf("%d%d",&x,&y);
		add(x,y,id);add(y,x,id)
	}
	int T;
	scanf("%d",&T);
	while (T --)
	{
		int x,y;
		id ++;
		scanf("%d%d",&x,&y);
		add(x,y,id);add(y,x,id);
		work();
		printf("%d\n",ans);
	}
	return 0;
}

