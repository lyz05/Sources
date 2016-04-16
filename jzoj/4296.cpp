#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 100000+5;
const LL inf=1e14+7;
struct node
{LL maxx,tag;} h[4*N];
struct node1
{int h,w,cost,id;} a[N];
int n;
LL f[N],g[N];

void down(int x)
{
	h[x+x].tag += h[x].tag;h[x+x+1].tag += h[x].tag;
	h[x+x].maxx += h[x].tag;h[x+x+1].maxx += h[x].tag;
	//h[x].maxx += h[x].tag;
	h[x].tag = 0;
}

void merge(int x)
{
	h[x].maxx = max(h[x+x].maxx , h[x+x+1].maxx);
}

void push(int x,int l,int r,int en,LL val)
{
	if (l==r && l==en)
	{
		if (val>h[x].maxx)
			h[x].maxx = val;
		return ;
	}
	down(x);
	int mid = (l+r)>>1;
	if (en<=mid) push(x+x,l,mid,en,val);
	else push(x+x+1,mid+1,r,en,val);
	merge(x);
}

void modify(int x,int l,int r,int en,LL val)
{
	if (r==en)
	{
		h[x].tag += val;h[x].maxx += val;
		return ;
	}
	down(x);
	int mid = (l+r)>>1;
	if (en<=mid) modify(x+x,l,mid,en,val);
	else 
	{
		modify(x+x,l,mid,mid,val);
		modify(x+x+1,mid+1,r,en,val);
	}
	merge(x);
}

LL query(int x,int l,int r,int en)
{
	if (r==en)
	{
		return h[x].maxx;
	}
	down(x);
	int mid = (l+r)>>1;
	if (en<=mid) return query(x+x,l,mid,en);
	else 
	{
		LL ret1 = query(x+x,l,mid,mid),
		    ret2 = query(x+x+1,mid+1,r,en);
		return max(ret1,ret2);
	}
	merge(x);
}

bool cmp(node1 A,node1 B) 
{return A.h<B.h;}
bool cmp1(node1 A,node1 B) 
{return A.id<B.id;}

int main()
{
	freopen("herbary.in","r",stdin);
	//freopen("herbary.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
		a[i].id = i,scanf("%d%d%d",&a[i].h,&a[i].w,&a[i].cost);
	sort(a+1,a+1+n,cmp);
	int last = 1;
	for (int i=1;i<n;i ++)
	{
		if (a[i].h!=a[i+1].h) a[i].h = last,last++;
		else a[i].h = last;
	}
	a[n].h = last;
	sort(a+1,a+1+n,cmp1);

	modify(1,0,n,n,-inf);
	push(1,0,n,0,0);
	for (int i=1;i<=n;i ++)
	{
		f[i] = query(1,0,n,a[i].h);
		f[i] += a[i].w;
		modify(1,0,n,a[i].h,-a[i].cost);
		push(1,0,n,a[i].h,f[i]);
	}
	modify(1,0,n,n,-inf);
	push(1,0,n,0,0);
	for (int i=n;i>=1;i --)
	{
		g[i] = query(1,0,n,a[i].h);
		g[i] += a[i].w;
		modify(1,0,n,a[i].h,-a[i].cost);
		push(1,0,n,a[i].h,g[i]);
	}
	LL ans = 0;
	for (int i=1;i<=n;i ++) ans = max(ans,f[i]+g[i]-a[i].w);
	printf("%lld\n",ans);
	return 0;
}
