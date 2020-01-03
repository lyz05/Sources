#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>
using namespace std;

typedef long long LL;
const int N = 10005,M = 50005;
struct node
{
	int y,next,w;
} h[2*M];

int n,m,U,V,s,tot,ans;
int cos[N],vis[N],e[N];
LL d[N];
list <int> q;

void add(int x,int y,int z)
{
	h[++ tot].y = y;
	h[tot].w = z;
	h[tot].next = e[x];
	e[x] = tot;
}

bool spfa(int u,int limit)
{
	if (cos[u]>limit) return 0;

	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[u] = 0;
	q.push_back(u);
	vis[u] = 1;
	while (!q.empty())
	{
		int x = q.front();q.pop_front();vis[x] = 0;
		for (int i=e[x];i;i=h[i].next)
		{
			int y = h[i].y;
			if (cos[y]>limit) continue;
			if (d[x]+h[i].w<d[y])
			{
				d[y] = d[x] + h[i].w;
				if (!vis[y])
				{
					if (d[y]<d[q.front()])
						q.push_front(y);
					else 	q.push_back(y);
					vis[y] = 1;
				}
			}
		}
	}
	return d[V]<=s;
}


int main()
{
	freopen("1251.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d%d%d%d",&n,&m,&U,&V,&s);
	for (int i=1;i<=n;i ++) scanf("%d",&cos[i]);
	for (int i=1;i<=m;i ++) 
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	int l = 0,r = 1000000000;
	ans = -1;
	while (l<=r)
	{
		int mid = (l+r)>>1;
		if (spfa(U,mid)) 
		{
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	printf("%d\n",ans);
	return 0;
}
