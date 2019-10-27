#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int N = 1e5+7;
int e[N],vis[N],d[N],n;
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

void spfa(int u)
{
	static queue<int> q;
	memset(d,124,sizeof d);
	memset(vis,0,sizeof vis);
	d[u] = 0;
	q.push(u);
	vis[u] = 1;
	while (!q.empty())
	{
		
	}
}

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
	}
	spfa(1);						//以1号结点为起点做单源最短路

	cout << d[n];
	return 0;
}
