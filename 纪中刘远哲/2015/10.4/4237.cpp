#include <cstdio>
#include <algorithm>
using namespace std;

//typedef long long LL;
typedef unsigned int LL;
const int N = 1e5+10;
const long long mo = (long long)1<<32;
struct node1
{
	LL s1,s2,s3,minn,p;
} h[4*N];

struct node
{int d,v;} a[N];

int n,m;
int q;

bool cmp(node A,node B)
{
	return A.d<B.d;
}

void update(int x)
{
	int l=x+x, r=x+x+1;
	h[x].s1 = (h[l].s1+h[r].s1);
	h[x].s2 = (h[l].s2+h[r].s2);
	h[x].s3 = (h[l].s3+h[r].s3);
	h[x].minn = min(h[l].minn,h[r].minn);
	h[x].p = ((h[l].p+h[r].p)+(h[l].s1*h[r].s1)) ;
}

void maketree(int x,int l,int r)
{
	if (l==r)
	{
		h[x].s3 = a[l].v*a[l].v*a[l].v;
		h[x].s2 = a[l].v*a[l].v;
		h[x].s1 = a[l].v;
		h[x].minn = a[l].v;
		h[x].p = 0;
		return;
	}
	int mid=(l+r)/2;
	maketree(x*2,l,mid);
	maketree(x*2+1,mid+1,r);
	update(x);
}


LL query2(int v,int l,int r,int x,int y) //平方和
{
	if (l==x && r==y)
		return (h[v].s2);
	//down(v);
	int mid=(l+r)/2; LL ret;
	if (y<=mid) ret=query2(v*2,l,mid,x,y);
	else if (x>mid) ret=query2(v*2+1,mid+1,r,x,y);
	else ret=(query2(v*2,l,mid,x,mid)+query2(v*2+1,mid+1,r,mid+1,y));
	update(v);
	return ret;
}

LL query1(int v,int l,int r,int x,int y) //和
{
	if (l==x && r==y) 
		return (h[v].s1);
	//down(v);
	int mid=(l+r)/2; LL ret;
	if (y<=mid) ret=query1(v*2,l,mid,x,y);
	else if (x>mid) ret=query1(v*2+1,mid+1,r,x,y);
	else ret=(query1(v*2,l,mid,x,mid)+query1(v*2+1,mid+1,r,mid+1,y));
	update(v);
	return ret;
}

LL query5(int v,int l,int r,int x,int y) //立方和
{
	if (l==x && r==y) 
		return (h[v].s3);
	//down(v);
	int mid=(l+r)/2; LL ret;
	if (y<=mid) ret=query5(v*2,l,mid,x,y);
	else if (x>mid) ret=query5(v*2+1,mid+1,r,x,y);
	else ret=(query5(v*2,l,mid,x,mid)+query5(v*2+1,mid+1,r,mid+1,y));
	update(v);
	return ret;
}

LL query3(int v,int l,int r,int x,int y) //最小值
{
	if (l==x && r==y) 
		return h[v].minn;
	//down(v);
	int mid=(l+r)/2; LL ret;
	if (y<=mid) ret = query3(v*2,l,mid,x,y);
	else if (x>mid) ret = query3(v*2+1,mid+1,r,x,y);
	else ret=min(query3(v*2,l,mid,x,mid),query3(v*2+1,mid+1,r,mid+1,y));
	update(v);
	return ret;
}

LL query4(int v,int l,int r,int x,int y) //询问p
{
	if (l==x && r==y) 
		return h[v].p;
	//down(v);
	int mid=(l+r)/2; LL ret;
	if (y<=mid) ret = query4(v*2,l,mid,x,y);
	else if (x>mid) ret = query4(v*2+1,mid+1,r,x,y);
	else ret=((query4(v*2,l,mid,x,mid)+query4(v*2+1,mid+1,r,mid+1,y))+(query1(v*2,l,mid,x,mid)*query1(v*2+1,mid+1,r,mid+1,y)));
	update(v);
	return ret;
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
	freopen("melancholy.in","r",stdin);
	//freopen("melancholy.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].d);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].v);
	sort(a + 1,a + 1 + n,cmp);

	maketree(1,1,n);
	while (q --)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		int l = half(x),r = half(y);
		if (a[r].d>y || r>n) r --;
		if (r-l+1<z) puts("0"); else
		{
			LL ans = 0;
			if (z==1) ans=(query1(1,1,n,l,r)-query3(1,1,n,l,r));
			if (z==2)
			{	
				LL ret3 = query3(1,1,n,l,r),ret4 = query4(1,1,n,l,r);
				ans=(ret4-(ret3*(query1(1,1,n,l,r)-ret3)));
				for (int i=1;i<=z;i ++) ans *= i;
			}
			if (z==3)
			{
				LL minn = query3(1,1,n,l,r);
				LL s3 = (query5(1,1,n,l,r)+(mo-minn*minn*minn)),/*3*/
				   s1 = (query1(1,1,n,l,r)+(mo-minn)),
				   s2 = (query2(1,1,n,l,r)+(mo-minn*minn));
				ans = (s1*s1*s1-3*s1*s2+2*s3);
			}
			printf("%u\n",ans);
		}
	}
	return 0;
}
