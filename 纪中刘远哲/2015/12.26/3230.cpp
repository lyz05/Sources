#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000005,INF = 1e9+7;
struct node
{
	int y,next;
} h[N*2];
int n,e[N],tot,ans,f[N][2],Q[N],fa[N];
bool vis[N];

void add(int x,int y)
{
	h[++ tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int now,int fa)
{
	int sum = 0,m1 = -INF,m2 = -INF,son = 0;
	for (int i=e[now];i;i=h[i].next)
	if (h[i].y!=fa)
	{
		int y = h[i].y;
		dfs(y,now);
		son ++;
		sum += f[y][1];
		int tmp = f[y][1] - f[y][0];
		if (tmp>m1)
		{
			m2 = m1;
			m1 = tmp;
		} else if (tmp>m2) m2 = tmp;
	}
	//if (son==0) f[now][0] = f[now][1] = 0;
	f[now][0] = min(sum+2*son,sum-m1+2*(son-1));
	f[now][1] = min(f[now][0],sum-m1-m2+2*(son-2));
}

void bfs(int x)
{
	int l=1,r=1;
	Q[l] = x;vis[x] = 1;
	while (l<=r)
	{
		int x = Q[l ++];
		for (int i=e[x];i;i=h[i].next)
		{
			int y = h[i].y;
			if (!vis[y]) Q[++ r] = y,vis[y]=1;else fa[x] = y;
		}
	}
	for (int i=r;i;i --)
	{
		int now = Q[i];
		int sum = 0,m1 = -INF,m2 = -INF,son = 0;
		for (int i=e[now];i;i=h[i].next)
		if (h[i].y!=fa[now])
		{
			int y = h[i].y;
			son ++;
			sum += f[y][1];
			int tmp = f[y][1] - f[y][0];
			if (tmp>m1)
			{
				m2 = m1;
				m1 = tmp;
			} else if (tmp>m2) m2 = tmp;
		}
		//if (son==0) f[now][0] = f[now][1] = 0;
		f[now][0] = min(sum+2*son,sum-m1+2*(son-1));
		f[now][1] = min(f[now][0],sum-m1-m2+2*(son-2));
	}
}

int main()
{
	freopen("3230.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d\n",&n);
	for (int i=1;i<n;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	bfs(1);
	ans = min(f[1][0],f[1][1]);
	printf("%d\n",ans+1);
	return 0;
}
