#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1005;
int n,m,ans;
int e[N],f[N],g[N],s[N];
struct node
{int y,next;} h[2*N];

void add(int x,int y)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

int dfs(int x,int fa)
{
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		if (y==fa) continue;
		dfs(y,x);
		f[x] += g[y];
		g[x] += max(f[y],g[y]);
	}
	f[x] += s[x];
	return max(f[x],g[x]);
}

int main()
{
	freopen("1154.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) scanf("%d",&s[i]);
	for (int i=1;i<=m;i ++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for (int i=1;i<=n;i ++) 
		if (!f[i] && !g[i]) 
			ans += dfs(i,0);
	printf("%d\n",ans);

	return 0;
}
