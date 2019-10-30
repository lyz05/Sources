#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5+7;
int e[N],d[N];
int n,m,tot;
queue <int> q;
struct Node
{
	int y,next;
} h[N];

void add(int x,int y)
{
	tot ++;
	h[tot].y=y;
	h[tot].next = e[x];
	e[x] = tot;
}

void bfs()
{
	q.push(1);
	d[1] = 0;
	while (!q.empty())
	{
		int now = q.front();q.pop();
		for (int i=e[now];i;i=h[i].next)
		{
			if (d[now]+1<d[h[i].y])
			{
				d[h[i].y] = d[now]+1;
				q.push(h[i].y);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y); 
	}
	for (int i=1;i<=n;i ++) d[i] = 1e9+7;
	bfs();
	cout << (d[n]!=1e9+7?d[n]:-1) << endl;
	return 0;
} 
