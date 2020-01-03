#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 1000+5;
struct node
{int y,z,next;} h[2*N];
int n,tot,k;
int e[N],dep[N],fa[N][20],vis[N];
LL a[N*N],dis[N][20];

void add(int x,int y,int z)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].z = z;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x)
{
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y,z = h[i].z;
		if (vis[y]) continue;
		vis[y] = 1;
		dep[y] = dep[x] + 1;
		fa[y][0] = x;
		dis[y][0] = z;
		dfs(y);
	}
}

void get(int x,int y,LL &dist,LL &cnt)
{
	cnt = dep[x]+dep[y];
	int i,j,flag = 1;
	if (dep[x]<dep[y]) swap(x,y);
	for (i=0;(1<<i)<=dep[x];i ++);
	i --;

	for (j=i;j>=0;j --)
		if (dep[x]-(1<<j)>=dep[y])
		{
			dist = dist + flag*dis[x][j];
			if (j==0) flag = -flag;
			x = fa[x][j];
		}
	//dep ÏàÍ¬
	if (x==y)
	{	
		cnt -= 2*dep[x];
		return;
	}
	for (j=i;j>=0;j --)
	{
		if (fa[x][j] && fa[x][j]!=fa[y][j])
		{
			dist = dist + flag*dis[x][j];
			if (j==0) flag = -flag;
			x = fa[x][j];
			dist = dist + dis[y][j];
			y = fa[y][j];
		}
	}
	cnt -= 2*dep[fa[x][0]];
	dist += flag*dis[x][0];
	dist += dis[y][0];
}

void prepar() //OK
{
	for (int j=1;(1<<j)<=n;j ++)
		for (int i=1;i<=n;i ++)
		if (fa[i][j-1])
		{
			fa[i][j] = fa[fa[i][j-1]][j-1];
			if (j==1) 
				dis[i][j]=dis[i][j-1]-dis[fa[i][j-1]][j-1];
			else 
				dis[i][j]=dis[i][j-1]+dis[fa[i][j-1]][j-1];
		}
}



int main()
{
	freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);

	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	vis[1] = dep[1] = 1;
	dfs(1);
	prepar();
	for (int i=1;i<=n;i ++)
		for (int j=i+1;j<=n;j ++)
		{
			//if (i==j) continue;
			LL cnt = 0,tmp = 0;
			get(i,j,tmp,cnt);
			if (cnt&1) 
				a[++ tot] = tmp;
		}
	sort(a+1,a+1+tot);
	if (a[k]) printf("%lld\n",a[k]); else puts("Stupid Mike");
	return 0;
}

