#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 3000+5,M = 3000+5;
struct node
{int y,z,id,next;} h[2*N];
struct node1
{int x,y;} a[M];
int n,m,del,ans;
int dep[N],fa[N],val[N],id[N],e[N],b[N],tr[4*N];
bool vis[N];

int calc(int x,int y)
{
	int ret = 0;
	if (dep[x]<dep[y]) swap(x,y);
	while (dep[x]>dep[y]) ret += (id[x]==del)?0:val[x],x = fa[x];
	while (x!=y)
	{
		ret += (id[x]==del)?0:val[x],x = fa[x];
		ret += (id[y]==del)?0:val[y],y = fa[y];
	}
	return ret;
}

void add(int x,int y,int z,int id)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].z = z;
	h[tot].next = e[x];
	h[tot].id = id;
	e[x] = tot;
}

void dfs(int x)
{
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y;
		if (vis[y]) continue;
		vis[y] = 1;
		dep[y] = dep[x] + 1;
		fa[y] = x;
		val[y] = h[i].z;
		id[y] = h[i].id;
		dfs(y);
	}
}

void maketree(int x,int l,int r)
{
	if (l==r)
	{
		tr[x] = b[l];
		return;
	}
	int mid = (l+r)>>1;
	maketree(x+x,l,mid);
	maketree(x+x+1,mid+1,r);
	tr[x] = tr[x+x]+tr[x+x+1];
}

void modify(int x,int l,int r,int st,int val)
{
	if (l==r && l==st)
	{
		tr[x] = val;
		return;
	}
	int mid = (l+r)>>1;
	if (st<=mid)
		modify(x+x,l,mid,st,val);
	else	modify(x+x+1,mid+1,r,st,val);
	tr[x] = tr[x+x]+tr[x+x+1];
}

int query(int x,int l,int r,int st,int en)
{
	if (l==st && r==en)
	{
		return tr[x];
	}
	int mid = (l+r)>>1;
	if (en<=mid)
		return query(x+x,l,mid,st,en);
	else if (st>mid) return query(x+x+1,mid+1,r,st,en);
	else return query(x+x,l,mid,st,mid)+query(x+x+1,mid+1,r,mid+1,en);
}

int main()
{
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		b[i] = z;
		add(x,y,z,i);add(y,x,z,i);
	}
	for (int i=1;i<=m;i ++)
		scanf("%d%d",&a[i].x,&a[i].y);
	
	ans = 1e9+7;

	if (n<=100 && m<=100)
	{
		dep[1] = 1;vis[1] = 1;
		dfs(1);
		for (int i=1;i<n;i ++)
		{
			del = i;
			int maxx = 0;
			for (int j=1;j<=m;j ++)
			{
				int tmp = calc(a[j].x,a[j].y);
				maxx = max(maxx,tmp);
			}
			ans = min(ans,maxx);
		}
	} else 

	{
		maketree(1,1,n-1);
		for (int i=1;i<n;i ++)
		{
			int maxx = 0;
			modify(1,1,n-1,i,0);
			for (int j=1;j<=m;j ++)
			{
				int tmp = query(1,1,n-1,a[j].x,a[j].y-1);
				maxx = max(maxx,tmp);
			}
			modify(1,1,n-1,i,b[i]);
			ans = min(ans,maxx);
		}
	}
	printf("%d\n",ans);
	return 0;
}

