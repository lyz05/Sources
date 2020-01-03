#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

struct node
{
	int f,tag;
}
int n,m,f[N],a[N],b[N];
LL ans;

void down(int x)
{
	int l = x+x,r = x+x+1;
	h[l].tag += h[x].tag;
	h[r].tag += h[x].tag;
	h[x].tag = 1;	
}
void update(int x,int l,int r)
{
	int mid = (l+r)>>1;
	h[x].f = h[x+x].f*pow(h[x+x].tag,mid-l+1)*
		h[x+x+1].f*pow(h[x+x+1].tag,r-mid);	
}

void maketree(int x,int l,int r)
{
	if (l==r)
	{
		h[x].f = f;
		h[x].tag = 1;
		return;
	}
	int mid = (l+r)>>1;
	maketree(x+x,l,mid);
	maketree(x+x+1,mid+1,r);
	update(x,l,r);
	h[x].tag = 1;
}

void change(int x,int l,int r,int st,int en,int val)
{
	if (l==st && en==r)
	{
		h[x].tag *= val;
		return;
	}
	down(x);
	int mid = (l+r)>>1;
	if (en<=mid) change(x+x,l,mid,st,en,val); else
	if (st>mid) change(x+x+1,mid+1,r,st,en,val); else
	{
		change(x+x,l,mid,st,mid,val);
		change(x+x+1,mid+1,r,mid+1,en,val);
	}
	update(x,l,r);
}

LL query(int x,int l,int r,int st,int en)
{
	if (l==st && en==r)
	{
		return h[x].f*pow(h[x].tag,(r-l+1));
	}
	down(x);
	int mid = (l+r)>>1;
	LL ret;
	if (en<=mid) ret=query(x+x,l,mid,st,en); else
	if (st>mid) ret=query(x+x+1,mid+1,r,st,en); else
	{
		ret=query(x+x,l,mid,st,mid)+
			query(x+x+1,mid+1,r,mid+1,en);
	}
	update(x,l,r);
	return ret;

}

int gcd(int x,int y)
{if (y==0) return x;else return gcd(y,x%y);}

void make()
{
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
			a[gcd(i,j)] ++;
}
LL work()
{
	memset(b,0,sizeof b);
	LL ret;	
}
int main()
{
	//freopen("3.in","r",stdin);
	//freopen("3.out","w",stdout);
	
	int T = 0;
	scanf("%d%d",&n,&m);
	len = min(n,m);
	for (int i=1;i<=len;i++) scanf("%d",f + i);
	scanf("%d",&T);

	make();
	maketree(1,1,len);
	printf("%lld\n",work());
	while (T --)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		change(1,1,len,x,y,z);
		printf("%lld\n",work());
	}
	return 0;
}
