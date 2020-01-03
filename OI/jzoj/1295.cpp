#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 1005,INF = 1061109567;
struct node
{
	int y,w,next;
} h[30000+N];
int n,t1,t2,tot;
int d[N],vis[N],cnt[N],e[N];

void add(int x,int y,int z)
{
	h[++ tot].y = y;
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
					cnt[y] ++;
					if (cnt[y]>n) 
					{
						puts("-1");
						exit(0);
					}
					q.push(y);
				}
			}
		}
	}
}

int main()
{
	freopen("1295.in","r",stdin);
	//freopen("1295.out","w",stdout);

	scanf("%d%d%d",&n,&t1,&t2);
	for (int i=1;i<=t1+t2;i ++) 
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (i<=t1) add(x,y,z); else add(y,x,-z);
	}
	for (int i=1;i<n;i ++) add(i+1,i,0);
	spfa(1);
	if (d[n]==INF) puts("-2"); else printf("%d\n",d[n]);

	return 0;
}
