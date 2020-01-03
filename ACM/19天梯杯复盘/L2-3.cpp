#include <iostream>
#include <stack>
using namespace std;

const int N = 1e5+7;
int rd[N],e[N],a[N];
int ans,maxx,tot,n,m;

struct node
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

void dfs(int dep,int x)
{
	a[x] = dep;
	for (int i = e[x];i;i = h[i].next)
	{
		dfs(dep+1,h[i].y);
	}
}

int main()
{
	freopen("L2-3.in","r",stdin);

	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> m;
		for (int j=1;j<=m;j ++)
		{
			int t;
			cin >> t;
			add(i,t);
			rd[t] ++;
		}
	}
	for (int i=1;i<=n;i ++)
		if (!rd[i]) dfs(1,i);
	for (int i=1;i<=n;i ++)
	{
		if (a[i]>maxx) 
		{
			maxx = a[i];
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;	
} 
