#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int N = 2e5+7;
int n,m,e[N],tot,color[N];
struct Node
{
	int y,next;
} h[N];

void add(int x,int y)
{
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

bool dfs(int x,int col)
{
	color[x] = col;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		if (!color[y])
		{
			if (!dfs(h[i].y,3-col)) return false;
		} else if (color[y]==col) return false;
		
	}
	return true;
}

int main()
{
	cin >> n >> m;
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y);add(y,x);
	}
	
	bool flag = 1;
	for (int i=1;i<=n;i ++)
	{
		if (!color[i]) flag = flag & 
			dfs(i,1);
	}
	cout << (flag?"Yes":"No") << endl;
	return 0;
} 
