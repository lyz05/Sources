#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5+5;
int n,m,e[N],rd[N],ans[N],tot;
bool p[N],flag;
queue<int> q;

struct Node
{
	int y,next;
} h[N];

void add(int x,int y)
{
	tot ++;
	rd[y] ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
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
	for (int i=1;i<=n;i ++) 
		if (!rd[i]) q.push(i);
	while (!q.empty())
	{
		int now = q.front();
		ans[++ ans[0]] = now;
		q.pop();
		for (int i=e[now];i;i=h[i].next)
		{
			rd[h[i].y] --;
			if (rd[h[i].y]==0) q.push(h[i].y);
		}
		e[now] = 0;
	}
	
	if (ans[0]==n) 
		for (int i=1;i<=n;i ++) 
			cout << ans[i] << " ";
	else cout << "-1" << endl;
	return 0;
} 
