#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned int LL;
const int N = 1e5+10;
struct node
{
	LL a[7];
} h[4*N];

struct node1
{int d,v;} a[N];

int n,m,eld[4*N];
int q;

node merge(node a,node b)
{
	node ret;
	memset(ret.a,0,sizeof ret.a);
	for (int i=0;i<=6;i ++)
		for (int j=0;j<=i;j ++)
		{
			ret.a[i] += a.a[j]*b.a[i-j];
		}
	return ret;
}

bool cmp(node1 A,node1 B)
{
	return A.d<B.d;
}

void maketree(int x,int l,int r)
{
	if (l==r)
	{
		eld[x] = l;
		h[x].a[0] = 1;
		h[x].a[1] = a[l].v;
		return;
	}
	int mid=(l+r)/2;
	maketree(x*2,l,mid);
	maketree(x*2+1,mid+1,r);
	if (a[eld[x*2]].v<a[eld[x*2+1]].v) eld[x] = eld[x*2];
	else eld[x] = eld[x+x+1];
	h[x] = merge(h[x+x],h[x+x+1]);
}


int get_wz(int x,int l,int r,int st,int en)
{
	if (l==st && r==en) return eld[x];
	int mid=(l+r)>>1;
	if (en<=mid) return get_wz(x+x,l,mid,st,en);
	else if (st>mid) return get_wz(x+x+1,mid+1,r,st,en);
	else
	{
		int x1=get_wz(x+x,l,mid,st,mid),x2=get_wz(x+x+1,mid+1,r,mid+1,en);
		if (a[x1].v<a[x2].v) return x1;else return x2;
	}
}

node get(int x,int l,int r,int st,int en)
{
	if (l==st && en==r) return h[x];
	int mid=(l+r)>>1;
	if (en<=mid) return get(x+x,l,mid,st,en); else
	if (st>mid) return get(x+x+1,mid+1,r,st,en); else
	return merge(get(x+x,l,mid,st,mid),get(x+x+1,mid+1,r,mid+1,en));
}

int half(int st)
{
	int l = 1 , r = n, ret = n + 1;
	while (l<=r)
	{
		int mid = (l+r) >> 1;
		if (a[mid].d>=st)
		{
			ret = mid;
			r = mid - 1; 
		} else	l = mid + 1;
	}
	return ret;
}

int main()
{
	freopen("4237.in","r",stdin);
	//freopen("melancholy.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].d);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].v);
	sort(a + 1,a + 1 + n,cmp);
	maketree(1,1,n);
	a[n+1].d = 1e9+7;

	while (q --)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		int l = half(x),r = half(y);
		if (a[r].d>y || r>n) r --;
		if (r-l<z) puts("0"); else
		{
			int bz=get_wz(1,1,n,l,r);
			node ans;
			if (bz==l) ans = get(1,1,n,l+1,r);
			else if (bz==r) ans = get(1,1,n,l,r-1);else
				ans=merge(get(1,1,n,l,bz-1),get(1,1,n,bz+1,r));
			for (int i=1;i<=z;i ++)
				ans.a[z] = ans.a[z] * (LL)i;
			printf("%u\n",ans.a[z]);
		}
	}
	return 0;
}
