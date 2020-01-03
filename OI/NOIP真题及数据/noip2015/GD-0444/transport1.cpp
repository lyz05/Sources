#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 3000+5,M = 3000+5;
struct node
{int y,z,id,next;} h[2*N];
struct node1
{int x,y;} a[M];
int n,m,del,ans;
int dep[N],fa[N],val[N],id[N],e[N];
bool vis[N];

int calc(int x,int y)
{
	int ret = 0;
	if (dep[x]<dep[y]) swap(x,y);
	while (dep[x]<dep[y]) ret += (id[x]==del)?0:val[x],x = fa[x];
	while (x!=y)
	{
		ret += (id[x]==del)?0:val[x],x = fa[x];
		ret += (id[y]==del)?0:val[y],y = fa[y];
	}
	return ret;
}

void add(int x,int y,int z,int id)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].z = z;
	h[tot].next = e[x];
	h[tot].id = id;
	e[x] = tot;
}

void dfs(int x)
{
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y;
		if (vis[y]) continue;
		vis[y] = 1;
		dep[y] = dep[x] + 1;
		fa[y] = x;
		val[y] = h[i].z;
		id[y] = h[i].id;
		dfs(y);
	}
}

int main()
{
	freopen("transport.in","r",stdin);
	//freopen("transport.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,i);add(y,x,z,i);
	}
	for (int i=1;i<=m;i ++)
		scanf("%d%d",&a[i].x,&a[i].y);


	dep[1] = 1;vis[1] = 1;
	dfs(1);
	ans = 1e9+7;
	for (int i=1;i<n;i ++)
	{
		del = i;
		int maxx = 0;
		for (int j=1;j<=m;j ++)
		{
			int tmp = calc(a[j].x,a[j].y);
			maxx = max(maxx,tmp);
		}
		ans = min(ans,maxx);
	}
	printf("%d\n",ans);

	return 0;
}

