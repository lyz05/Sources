#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 1000+5,M = N*(N-1)/2;
struct node
{
	int y,d,next;
} h[N*2];
int n,m,tot;
int a[M],e[N];
bool vis[N];

void add(int x,int y,int z)
{
	h[++ tot].y = y;
	h[tot].d = z;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x,int from,int dis)
{
	if (from<x) a[++ a[0]] = dis;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		if (!vis[y])
		{
			vis[y] = 1;
			dfs(y,from,dis+h[i].d);
		}
	}
}

bool cmp(int x,int y){return x>y;}

int main()
{
	freopen("3329.in","r",stdin);
	//freopen("3329.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	for (int i=1;i<=n;i ++) 
	{
		memset(vis,0,sizeof vis);
		vis[i] = 1;
		dfs(i,i,0);
	}
	sort(a+1,a+1+a[0],cmp);
	for (int i=1;i<=m;i ++) printf("%d\n",a[i]);
	return 0;
}
