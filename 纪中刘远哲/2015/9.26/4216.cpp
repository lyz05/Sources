#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5,M = 1e5 + 5,mo = 7459;
struct node
{
	int v1,v2,add,cnt;
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

int place(int x,int l,int r,int st,int del)
{
	if (l==r)
	{
		h[x].cnt -= del;
		return l;
	}
	int ret,mid=(l+r)/2;
	if (st<=h[x*2].cnt) 
		ret = place(x+x,l,mid,st,del);
	else 
		ret = place(x+x+1,mid+1,r,st-h[x*2].cnt,del);
	h[x].cnt-=del;
	return ret;
}

int calc(int x)
{
	return ((2*h[x].v2*h[x].add+h[x].add*h[x].add%mo*h[x].cnt)%mo+mo)%mo;
}

void down(int x)
{
	int l = x+x, r = x+x+1;
	if (h[l].cnt) h[l].add = (h[l].add + h[x].add) % mo;
	if (h[r].cnt) h[r].add = (h[r].add + h[x].add) % mo;
	h[x].add = 0;
}

void update(int x)
{
	int l=x+x, r=x+x+1;
	h[x].v1 = (h[l].v1+h[r].v1+calc(l)+calc(r))%mo;
	h[x].v2 = (h[l].v2+h[r].v2+h[l].add*h[l].cnt+h[r].add*h[r].cnt)%mo;
	h[x].cnt = h[l].cnt+h[r].cnt;
}

void maketree(int x,int l,int r,int st)
{
	h[x].add = 0;
	if (l==r)
	{
		if (!h[x].cnt) return;
		h[x].v1 = a[st]*a[st]%mo;
		h[x].v2 = a[st]%mo;
		return;
	}
	int mid=(l+r)/2;
	maketree(x*2,l,mid,st);
	maketree(x*2+1,mid+1,r,st+h[x*2].cnt);
	update(x);
}

void ins(int x,int l,int r,int p,int q)
{
	if (l==r){
		h[x].v1=q*q%mo;
		h[x].v2=q%mo;
		h[x].add=0;
		++h[x].cnt;
		return;
	}
	down(x);
	int mid=(l+r)/2;
	if (p<=mid) ins(x*2,l,mid,p,q); else ins(x*2+1,mid+1,r,p,q);
	update(x);
}

void add(int v,int l,int r,int x,int y,int z)
{
	if (l==x && r==y){
		if (h[v].cnt) h[v].add=(h[v].add+z)%mo;
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

int query(int v,int l,int r,int x,int y)
{
	if (l==x && r==y) 
		return (h[v].v1+calc(v))%mo;
	down(v);
	int mid=(l+r)/2, ret;
	if (y<=mid) ret=query(v*2,l,mid,x,y);
	else if (x>mid) ret=query(v*2+1,mid+1,r,x,y);
	else ret=(query(v*2,l,mid,x,mid)+query(v*2+1,mid+1,r,mid+1,y))%mo;
	update(v);
	return ret;
}


int main()
{
	freopen("mission.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	scanf("%d",&m);
	for (int i=1;i<=m;i ++)	
	{
		char st[10];
		scanf("%s%d%d",st,&q[i][1],&q[i][2]);
		if (st[0] == 'I') q[i][0]=0, n ++;
		if (st[0] == 'A'){q[i][0]=1; scanf("%d",&q[i][3]);}
		if (st[0] == 'Q') q[i][0]=2;	
	}
	mark(1,1,n);//标记点
	for (int i=m;i;i --)
		if (q[i][0]) 
			q[i][1]=place(1,1,n,q[i][1],0),
			q[i][2]=place(1,1,n,q[i][2],0);
		else	
			q[i][1]=place(1,1,n,q[i][1],1);
	//修正读入
	maketree(1,1,n,1);
	for (int i=1;i<=m;i ++)
		if (!q[i][0]) ins(1,1,n,q[i][1],q[i][2]);
		else if (q[i][0]==1) add(1,1,n,q[i][1],q[i][2],q[i][3]);
		else printf("%d\n",query(1,1,n,q[i][1],q[i][2]));

	return 0;

}
