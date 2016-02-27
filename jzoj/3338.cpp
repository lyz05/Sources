#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 400000+5;
struct node
{
	int id,v,dfs,l,r;
} a[N];
struct node1
{
	int y,next;
} hh[N*2];

int h[4*N],e[N],b[N],f[N],tot,n;

void add(int x,int y)
{
	tot ++;
	hh[tot].y = y;
	hh[tot].next = e[x];
	e[x] = tot;
}


void dfs(int x)
{
	b[++b[0]] = x;
	a[x].l = b[0];
	for (int i=e[x];i;i = hh[i].next) dfs(hh[i].y);
	a[x].r = b[0];
}

int cmp(node A,node B)
{
	if (A.v==B.v) return A.dfs>B.dfs;
	return A.v<B.v;
}

void modify(int x,int l,int r,int st,int v)
{
	if (l==r && r==st)
	{
		h[x] = v;
		return;
	}
	int mid = (l+r)>>1;
	if (st<=mid) modify(x+x,l,mid,st,v);
	else modify(x+x+1,mid+1,r,st,v);
	h[x] = max(h[x+x],h[x+x+1]);
}
int query(int x,int l,int r,int st,int en)
{
	if (l==st && r==en)
		return h[x];
	int mid = (l+r)>>1;
	if (en<=mid) return query(x+x,l,mid,st,en);
	else if (st>mid) return query(x+x+1,mid+1,r,st,en);
	else
	{
		return max(query(x+x,l,mid,st,mid),query(x+x+1,mid+1,r,mid+1,en));
	}
}

int main()
{
	freopen("3338.in","r",stdin);
	//freopen("3338.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int x;
		scanf("%d",&x);
		add(x,i);
	}
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].v),a[i].id = i;

	dfs(1);
	for (int i=1;i<=n;i ++) a[b[i]].dfs = i;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i ++)
	{
		f[a[i].id] = query(1,1,n,a[i].l,a[i].r)+1;
		modify(1,1,n,a[i].dfs,f[a[i].id]);
	}
	for (int i=1;i<=n;i ++) printf("%d ",f[i]);
	printf("\n");
	return 0;
}
