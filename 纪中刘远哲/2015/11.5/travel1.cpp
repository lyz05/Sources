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
int e[N],dep[N],dis[N],fa[N],vis[N];
LL a[N*N];

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
		fa[y] = x;
		dis[y] = z;
		dfs(y);
	}
}

void get(int x,int y,LL &dist,LL &cnt)
{
	cnt = dep[x]+dep[y];
	if (dep[x]<dep[y]) swap(x,y);
	LL dis1 = 0,dis2 = 0;
	int p = 1,q = 1;
	while (dep[x]>dep[y]) dis1 += p*dis[x],p=-p,x = fa[x];
	while (x!=y)
	{
		dis1 += p*dis[x],p=-p,x = fa[x];
		dis2 += q*dis[y],q=-q,y = fa[y];
	}
	dist = dis1 + dis2;
	cnt -= 2*dep[x];
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
	//prepar();
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

