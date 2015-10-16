#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000+5;
struct node
{
	int x,y,id;
} a[N];
int id[N],ans[N],h[4*N];
int n;

bool cmp1(int i,int j)
{
	return a[i].y<a[j].y;
}

bool cmp(node a,node b)
{
	return a.x>b.x;
}

void change(int x,int l,int r,int st,int val)
{
	if (l==r)
	{
		h[x] = val;
		return;
	}
	int mid = (l+r) >> 1;
	if (st<=mid) change(x+x,l,mid,st,val);
	else change(x+x+1,mid+1,r,st,val);
	h[x] = max(h[x+x],h[x+x+1]);
}

int query(int x,int l,int r,int st,int en)
{
	if (st>en) return 0;
	if (l==st && r==en)
	{
		return h[x];
	}
	int mid = (l+r)>>1;
	if (en<=mid) return query(x+x,l,mid,st,en);
	else if (mid<st) return query(x+x+1,mid+1,r,st,en);
	else 
	{
		int ret1,ret2;
		ret1 = query(x+x,l,mid,st,mid);
		ret2 = query(x+x+1,mid+1,r,mid+1,en);
		return max(ret1,ret2);
	}
}


int main()
{
	freopen("4214.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id = i;
		id[i] = i;
	}
	sort(id + 1,id + 1 + n,cmp1);
	for (int i=1;i<=n;i++) a[id[i]].y = i;
	sort(a + 1,a + 1 + n,cmp);

	for (int i=1;i<=n;i ++)
	{
		int y = a[i].y ,id = a[i].id;
		ans[id] = query(1,1,n,y+1,n) + 1;
		change(1,1,n,y,ans[id]);
	}
	for (int i=1;i<=n;i ++) printf("%d\n",ans[i]);
	return 0;
}
