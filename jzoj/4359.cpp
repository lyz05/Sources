#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100000+5,mo = 100000007;
typedef long long LL;
struct node
{
	LL ans,front,back,now,len;
} h[10][4*N];
int n,m,a[N];
LL ans;

void update(node &now,node &L,node &R)
{
	//int L = x+x,R = x+x+1;
	now.len = L.len+R.len;
	now.now = L.now^R.now;
	now.ans = (L.ans+R.ans+
		L.back*(R.len-R.front)+
		(L.len-L.back)*R.front)%mo;
	if (L.now)
		now.front = L.front + (R.len-R.front);
	else	now.front = L.front + R.front;
	if (R.now)
		now.back = R.back + (L.len-L.back);
	else	now.back = R.back + L.back;

}

void make(int p,int x,int l,int r)
{
	if (l==r)
	{
		h[p][x].front = h[p][x].back = 
			h[p][x].ans = h[p][x].now = (a[l]>>p)%2;
		h[p][x].len = 1;
		return;
	}
	int mid = (l+r)>>1;
	make(p,x+x,l,mid);make(p,x+x+1,mid+1,r);
	update(h[p][x],h[p][x+x],h[p][x+x+1]);
}

void modify(int p,int x,int l,int r,int xx,int y)
{
	if (l==r)
	{
		h[p][x].front = h[p][x].back = 
			h[p][x].ans = h[p][x].now = (y>>p)%2;
		return;
	}
	int mid = (l+r)>>1;
	if (xx<=mid) modify(p,x+x,l,mid,xx,y);
	else	modify(p,x+x+1,mid+1,r,xx,y);
	update(h[p][x],h[p][x+x],h[p][x+x+1]);
}

node query(int p,int x,int l,int r,int st,int en)
{
	node now;
	if (l==st && en==r)
	{
		now = h[p][x];
		return now;
	}
	int mid = (l+r)>>1;
	if (en<=mid) return query(p,x+x,l,mid,st,en);
	else if (st>mid) return query(p,x+x+1,mid+1,r,st,en);
	else 
	{
		node L,R;
		/*	
		h[p][x].ans = h[p][L].ans+h[p][R].ans+
			h[p][L].back*(h[p][R].len-h[p][R].front)+
			(h[p][L].len-h[p][L].back)*h[p][R].front;
		*/
		L = query(p,x+x,l,mid,st,mid);
		R = query(p,x+x+1,mid+1,r,mid+1,en);
		update(now,L,R);
		return now;
	}
}

int main()
{
	freopen("4359.in","r",stdin);
	//freopen("4359.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i]);
	for (int i=0;i<10;i ++) make(i,1,1,n);

	scanf("%d\n",&m);
	for (int i=1;i<=m;i ++)
	{
		char ch;
		int x,y;
		LL tmp;
		ans = 0;
		scanf("%c %d %d\n",&ch,&x,&y);
		for (int j=9;j>=0;j --)
		{
			if (ch=='M') 
				modify(j,1,1,n,x,y);
			else 
			{
				tmp = query(j,1,1,n,x,y).ans;
				ans = ((ans<<1)+tmp)%mo;
			}
		}
		if (ch=='Q') printf("%lld\n",ans);
	}
	return 0;
}
