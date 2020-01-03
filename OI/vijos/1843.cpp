#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 10005,M = 50005;
struct node
{
	int y,len,next;
} h[2*M];
struct node1
{
	int x,y,z;
	bool operator < (const node1 &A) const {return z>A.z;}
} a[M];

int n,m;
int e[N],fa[N][15],f[N][15],dep[N],H[N];
bool vis[N];

int gf(int x)
{
	if (x==H[x]) return x;else return H[x] = gf(H[x]);
}

void add(int x,int y,int z)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].len = z;
	h[tot].next = e[x];
	e[x] = tot;
}

void link(int x,int y,int z)
{
	int i = gf(x),j = gf(y);
	if (i!=j)
	{
		H[i] = j;
		add(x,y,z);
		add(y,x,z);
	}
}

void dfs(int x)
{
	for (int i=e[x];i;i = h[i].next)
	{
		int &y = h[i].y,&z = h[i].len;
		if (!vis[y])
		{
			vis[y] = 1;
			dep[y] = dep[x] + 1;
			fa[y][0] = x;
			f[y][0] = z;
			dfs(y);
		}
	}
}

int getans(int x,int y)
{
	if (gf(x)!=gf(y)) return -1;
	int maxl,ans = 1e9+7;
	if (dep[y]>dep[x]) swap(x,y);
	for (maxl=1;(1<<maxl)<=n;maxl ++) ;
	for (int i=maxl;i>=0;i --)
		if (dep[fa[x][i]]>=dep[y])
		{	
			ans = min(f[x][i],ans);
			x = fa[x][i];
		}
	if (x==y) return ans;
	for (int i=maxl;i>=0;i --)
		if (fa[x][i]!=fa[y][i])
		{
			ans = min(ans,f[x][i]),ans = min(ans,f[y][i]);
			x = fa[x][i], y = fa[y][i];
		}
	ans = min(ans,f[x][0]),ans = min(ans,f[y][0]);
	return ans;
}

int main()
{
	freopen("1843.in","r",stdin);
	//freopen("1843.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++) 
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+1+m);
	for (int i=1;i<=n;i ++) H[i] = i;
	for (int i=1;i<=m;i ++) link(a[i].x,a[i].y,a[i].z);
	for (int i=1;i<=n;i ++)
		if (!vis[i])
		{
			dep[i] = 1;vis[i] = 1;
			dfs(i);
		}
	for (int j=1;(1<<j)<=n;j ++)
	       for (int i=1;i<=n;i ++)
	       {	       
			fa[i][j] = fa[fa[i][j-1]][j-1];
			f[i][j] = min(f[i][j-1],f[fa[i][j-1]][j-1]);
	       }
	int T;
	scanf("%d",&T);
	while (T --)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",getans(x,y));
	}

	return 0;
}
