#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100,M = 2000;
int e[N],vis[N],x[M],y[M],z[M],d[N];
int n;
struct node
{int y,next,w;} h[2*M];

void add(int x,int y,int z)
{
	static int tot;
	++ tot;
	h[tot].y = y;
	h[tot].w = z;
	h[tot].next = e[x];
	e[x] = tot;
}

void spfa(int u)
{
	static queue <int> q;
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[u] = 0;
	q.push(u);
	vis[u] = 1;
	while (!q.empty())
	{
		int x = q.front();q.pop();vis[x] = 0;
		for (int i=e[x];i;i=h[i].next)
		{
			int y = h[i].y;
			if (d[x]+h[i].w<d[y])
			{
				d[y] = d[x] + h[i].w;
				if (!vis[y])
				{
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);		//无向边
	}
	spfa(1);				//以1号结点为起点做单源最短路
	
	for (int i=1;i<=n;i ++) printf("%d ",d[i]);
	puts("");
	return 0;
}
