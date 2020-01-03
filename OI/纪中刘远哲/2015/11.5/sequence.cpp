#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 400000+5,M = 400000+5;
struct node
{int w,p,id;} a[N];
struct node1
{
	LL x,y,tot;
} h[4*N];
struct node2
{int x,y,z,id;} b[M];
int n,q;
LL ans[M];

bool cmp1(node A,node B) {return A.w<B.w;}
bool cmp2(node2 A,node2 B) {return A.z<B.z;}

void update(int x)
{
	int l=x+x, r=x+x+1;
	h[x].x = h[l].x+h[r].x;
	h[x].y = h[l].y+h[r].y;
	h[x].tot = h[l].tot + h[r].tot;
}

void add(int v,int l,int r,int x,int y,int z)
{
	if (l==x && r==y){
		h[v].x = z;
		h[v].y = (LL)z*z;
		h[v].tot = 1;
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) add(v*2,l,mid,x,y,z);
	else if (x>mid) add(v*2+1,mid+1,r,x,y,z);
	else {
		add(v*2,l,mid,x,mid,z);
		add(v*2+1,mid+1,r,mid+1,y,z);
	}
	update(v);
}

LL query2(int v,int l,int r,int x,int y) //和
{
	if (l==x && r==y) 
		return (h[v].x);
	int mid=(l+r)/2; LL ret;
	if (y<=mid) ret=query2(v*2,l,mid,x,y);
	else if (x>mid) ret=query2(v*2+1,mid+1,r,x,y);
	else ret=(query2(v*2,l,mid,x,mid)+query2(v*2+1,mid+1,r,mid+1,y));
	update(v);
	return ret;
}

LL query1(int v,int l,int r,int x,int y) //平方和
{
	if (l==x && r==y) 
		return (h[v].y);
	int mid=(l+r)/2; LL ret;
	if (y<=mid) ret=query1(v*2,l,mid,x,y);
	else if (x>mid) ret=query1(v*2+1,mid+1,r,x,y);
	else ret=(query1(v*2,l,mid,x,mid)+query1(v*2+1,mid+1,r,mid+1,y));
	update(v);
	return ret;
}

LL query3(int v,int l,int r,int x,int y) //cnt
{
	if (l==x && r==y) 
		return (h[v].tot);
	int mid=(l+r)/2; LL ret;
	if (y<=mid) ret=query3(v*2,l,mid,x,y);
	else if (x>mid) ret=query3(v*2+1,mid+1,r,x,y);
	else ret=(query3(v*2,l,mid,x,mid)+query3(v*2+1,mid+1,r,mid+1,y));
	update(v);
	return ret;
}

int main()
{
	freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);

	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i ++) 
		scanf("%d%d",&a[i].w,&a[i].p),a[i].id=i;
	for (int i=1;i<=q;i ++) 
		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z),b[i].id=i;
	sort(a+1,a+1+n,cmp1),sort(b+1,b+1+q,cmp2);

	int j=1;
	for (int i=1;i<=q;i ++)
	{
		while (j<=n && a[j].w<=b[i].z)
		       add(1,1,n,a[j].id,a[j].id,a[j].p),j ++;
		LL ret2 = query1(1,1,n,b[i].x,b[i].y);
		LL ret1 = query2(1,1,n,b[i].x,b[i].y);
		LL cnt  = query3(1,1,n,b[i].x,b[i].y);
		if (cnt==0) ans[b[i].id] = -1;
		else ans[b[i].id] = cnt*ret2-ret1*ret1;
	}
	for (int i=1;i<=q;i ++) 
		if (ans[i]==-1) puts("empty");
			else printf("%lld\n",ans[i]);
	return 0;
}

