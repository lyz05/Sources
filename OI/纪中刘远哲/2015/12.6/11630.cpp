#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 10000+5,M = 100005,K = 10005;
struct Edge
{
	int y,len,next;
} h[2][M];

struct node
{
	int x,len,f;
	friend bool operator<(node x,node y)
	{
		if (x.f==y.f) return x.len>y.len;
		return x.f>y.f;
	}
	node(int a,int b,int c) {x = a,len = b;f = c;}
};

priority_queue <node> Q;
int n,m,k,ans;
int e[2][N],d[N],vis[N],tot[2];

void add(int kind,int x,int y,int z)
{
	h[kind][++ tot[kind]].y = y;
	h[kind][tot[kind]].next = e[kind][x];
	h[kind][tot[kind]].len = z;
	e[kind][x] = tot[kind];
}

int A_star(int x)
{
	//if (dis[x]==INF) return -1;
	node now = node(x,0,0+d[n]);
	Q.push(now);
	while (!Q.empty())
	{
		now = Q.top();Q.pop();
		if (now.x==n && now.f!=ans)
		{
			ans = now.f;
			k --;
			if (k==0) return now.f;
		}
		for (int i=e[0][now.x];i;i = h[0][i].next)
		{
			int y = h[0][i].y;
			node next = node(y,now.len+h[0][i].len,now.len+h[0][i].len+d[y]);
			Q.push(next);
		}
	}
	return -1;
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
		for (int i=e[1][x];i;i=h[1][i].next)
		{
			int y = h[1][i].y;
			if (d[x]+h[1][i].len<d[y])
			{
				d[y] = d[x] + h[1][i].len;
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
	freopen("1163.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		char ch;
		while(ch = getchar(),ch != 10);
		add(0,x,y,z);add(1,y,x,z);
	}
	spfa(n);
	ans = A_star(1);
	printf("%d\n",ans);

	return 0;
}
