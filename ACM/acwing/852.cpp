#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int N = 1e5+7;
int e[N],vis[N],d[N],n,m,cnt[N];
//cnt数组记录每个点的最短路的路径长度
//如果大于n，说明一定存在负环。 
struct Node
{
	int y,next,w;
} h[N];

void add(int x,int y,int z)
{
	static int tot;
	++ tot;
	h[tot].y = y;
	h[tot].w = z;
	h[tot].next = e[x];
	e[x] = tot;
}

bool spfa(int u)
{
	static queue<int> q;
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	d[u] = 0;
	q.push(u); 
	vis[u] = 1;
	while (!q.empty())
	{
		int x = q.front();q.pop();vis[x] = 0;
		for (int i=e[x];i;i = h[i].next)
		{
			int y = h[i].y;
			if (d[x]+h[i].w<d[y])
			{
				d[y] = d[x]+h[i].w;
				cnt[y] = cnt[x]+1;
				if (cnt[y]>n) return 1; 
				if (!vis[y])
				{
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
	return 0;
}

int main()
{
	//freopen("852.in","r",stdin);
	cin >> n >> m;
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
	}
	memset(d,124,sizeof d);
	for (int u=1;u<=n;u ++)
	{
		if (d[u]==2088533116 && spfa(u)) 
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}
