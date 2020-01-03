#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100000+5, M = 100000+5 , mo = 7459;
struct node
{
	int x,y,z,type;
} q[M];
struct node1
{
	int v1,v2,add;
} tr[4*N];
int n,m;
int a[N];
vector <int> b;
bool flag = 1;

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a + i);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) 
	{
		char s[10];
		int x,y,z=0,type=0;
		scanf("%s%d%d\n",s,&x,&y);
		if (s[0] == 'I') type = 1;
		if (s[0] == 'A')
		{
			scanf("%d",&z);	
			type = 2;
		}
		if (s[0] == 'Q') type = 3;
		q[i].x = x;
		q[i].y = y;
		q[i].z = z;
		q[i].type = type;
		if (type == 1) flag = 0;
	}
}

void down(int x)
{
	int l = x+x, r = l+1;
	//if (h[l].cnt)
		h[l].add = (h[l].add + h[x].add) %mo;
	//if (h[r].cnt)
		h[r].add = (h[r].add + h[x].add) %mo;
	h[x].add = 0;
}

void up(int x)
{
	int l = x+x,r = l + 1;
	h[x].v1 = (h[l].v1+h[r].v1+calc(l)+calc(r))%mo;
	h[x].v2 = (h[l].v2+h[x].v2+h[l].add*)
}

void build(int x,int l,int r)
{
	if (l == r)
	{
		tr[x].v1 = (a[l]*a[l])%mo;
		tr[x].v2 = a[l];
		tr[x].add = 0;
		return ;
	}
	int mid = (l+r) >> 1;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
	up(x,l,r);
}

void add(int x,int l,int r,int st,int en,int val)
{
	if (l==st && r==en)
	{
		tr[x].add += val;
		return ;
	}
	down(x,l,r);
	int mid = (l+r)>>1;
	if (en<=mid) add(x+x,l,mid,st,en,val);
	else if (mid<st) add(x+x+1,mid+1,r,st,en,val);
	else 
	{
		add(x+x,l,mid,st,mid,val);
		add(x+x+1,mid+1,r,mid+1,en,val);
	}
	up(x,l,r);
}

int query(int x,int l,int r,int st,int en)
{
	if (l==st && r==en)
	{
		down(x,l,r);
		return tr[x].v1;
	}
	down(x,l,r);
	int mid = (l+r)>>1;
	if (en<=mid) return query(x+x,l,mid,st,en);
	else if (mid<st) return query(x+x+1,mid+1,r,st,en);
	else 
	{
		int ret1,ret2;
		ret1 = query(x+x,l,mid,st,mid);
		ret2 = query(x+x+1,mid	+1,r,mid+1,en);
		return (ret1+ret2)%mo;
	}
	up(x,l,r);
}

void work2()
{
	build(1,1,n);
	for (int i=1;i<=m;i ++)
	{
		int x = q[i].x , y = q[i].y ,z = q[i].z , kind = q[i].type;
		if (kind == 2) add(1,1,n,x,y,z);
		if (kind == 3) printf("%d\n",query(1,1,n,x,y));
	}
}

int main()
{
	freopen("mission.in","r",stdin);
	//freopen("mission.out","w",stdout);
	init();
	
	if (flag) work2();
	

	//work2();
	return 0;
}
