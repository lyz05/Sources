#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5+10,M = 1e5 + 10;
struct node
{
	LL x,y,sa,cnt;
} h[4*N];

int n,m;
int q[M][4],a[N];

void mark(int x,int l,int r)
{
	h[x].cnt = r-l+1;
	if (l==r) return;
	int mid = (l+r)>>1;
	mark(x+x,l,mid);mark(x+x+1,mid+1,r);
}

int calc(int x) 
{
	return ((2*h[x].y*h[x].sa+h[x].sa*h[x].sa*h[x].cnt));
}

void down(int x)
{
	int l = x+x, r = x+x+1;
	if (h[l].cnt) h[l].sa = (h[l].sa + h[x].sa);
	if (h[r].cnt) h[r].sa = (h[r].sa + h[x].sa);
	h[x].sa = 0;
}

void update(int x)
{
	int l=x+x, r=x+x+1;
	h[x].x = (h[l].x+h[r].x+calc(l)+calc(r));
	h[x].y = (h[l].y+h[r].y+h[l].sa*h[l].cnt+h[r].sa*h[r].cnt);
	h[x].cnt = h[l].cnt+h[r].cnt;
}

void maketree(int x,int l,int r,int st)
{
	h[x].sa = 0;
	if (l==r)
	{
		if (!h[x].cnt) return;
		h[x].x = a[st]*a[st];
		h[x].y = a[st];
		return;
	}
	int mid=(l+r)/2;
	maketree(x*2,l,mid,st);
	maketree(x*2+1,mid+1,r,st+h[x*2].cnt);
	update(x);
}



void add(int v,int l,int r,int x,int y,int z)
{
	if (l==x && r==y){
		if (h[v].cnt) h[v].sa=(h[v].sa+z);
		return;
	}
	down(v);
	int mid=(l+r)/2;
	if (y<=mid) add(v*2,l,mid,x,y,z);
	else if (x>mid) add(v*2+1,mid+1,r,x,y,z);
	else {
		add(v*2,l,mid,x,mid,z);
		add(v*2+1,mid+1,r,mid+1,y,z);
	}
	update(v);
}

LL query2(int v,int l,int r,int x,int y) //平方和
{
	if (l==x && r==y) 
		return (h[v].x+calc(v));
	down(v);
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
		return (h[v].y+h[v].sa*h[v].cnt);
	down(v);
	int mid=(l+r)/2; LL ret;
	if (y<=mid) ret=query1(v*2,l,mid,x,y);
	else if (x>mid) ret=query1(v*2+1,mid+1,r,x,y);
	else ret=(query1(v*2,l,mid,x,mid)+query1(v*2+1,mid+1,r,mid+1,y));
	update(v);
	return ret;
}

int main()
{
	freopen("spaly.in","r",stdin);
	//freopen("spaly.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	for (int i=1;i<=m;i ++)	
	{
		//int type = 0;
		scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);
		if (q[i][0] == 0) {
			q[i][0]=1;
			q[i][3]=q[i][2];
			q[i][2]=q[i][1];
	       	}
		else if (q[i][0] == 1) scanf("%d",&q[i][3]);
	}
	mark(1,1,n);//标记点
	maketree(1,1,n,1);
	for (int i=1;i<=m;i ++)
	{
		if (q[i][0]==1) add(1,1,n,q[i][1],q[i][2],q[i][3]);
		if (q[i][0]==2) printf("%lld\n",query1(1,1,n,q[i][1],q[i][2]));
		if (q[i][0]==3) {
			LL ret2 = query2(1,1,n,q[i][1],q[i][2]),
			    ret1 = query1(1,1,n,q[i][1],q[i][2]),
			    len = (q[i][2]-q[i][1]+1);
			double pj = (double)ret1/len;
			double ans = (len*pj*pj+ret2-2*pj*ret1)/len;
			printf("%.8lf\n",ans);
		}
	}

	return 0;

}
