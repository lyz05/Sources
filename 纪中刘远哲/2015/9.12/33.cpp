#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100000, M = 100000 , mo = 7459;
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
	for (int i=1;i<=n;i++)
	{	
		scanf("%d",a + i);
		b.push_back(a[i]);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++) 
	{
		char s[10];
		int x,y,z=0,type;
		scanf("%s%d%d",s,&x,&y);
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

void work1()
{
	for (int i=1;i<=m;i ++)
	{
		vector <int>::iterator it;
		it = b.begin();
		int x = q[i].x , y = q[i].y ,z = q[i].z , kind = q[i].type;
		if (kind == 2) 
			for (int j=x-1;j<=y-1;j ++)
				b[j] += z;
		if (kind == 1)
			b.insert(it+x-1,y);
		if (kind == 3)
		{
			int ans = 0;
			for (int j=x-1;j<=y-1;j ++)
				ans += b[j]*b[j] , ans %= mo;
			printf("%d\n",ans);
		}
		//for (int i=0;i<b.size();i++) printf("%d ",b[i]);
		//puts("");
	}
}

void down(int x,int l,int r)
{
	if (l!=r)
	{
		tr[x+x].add += tr[x].add;
		tr[x+x+1].add += tr[x].add;
	}
	tr[x].v1 = tr[x].v1 + 2*tr[x].add*tr[x].v2 + tr[x].add*tr[x].add*(r-l+1);
	tr[x].v2 += tr[x].add * (r-l+1);
	tr[x].add = 0;
}

void up(int x,int l,int r)
{
	int mid = (l+r) >> 1;
	down(x+x,l,mid);down(x+x+1,mid+1,r);
	tr[x].v1 = tr[x+x].v1 + tr[x+x+1].v1;
	tr[x].v2 = tr[x+x].v2 + tr[x+x+1].v2;
	//tr[x].add = tr[x+x].add + tr[x+x+1].add;
}

void build(int x,int l,int r)
{
	if (l == r)
	{
		tr[x].v1 = a[l]*a[l];
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
		ret2 = query(x+x+1,mid+1,r,mid+1,en);
		return ret1+ret2;
	}
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
	//freopen("3.in","r",stdin);
	//freopen("mission.out","w",stdout);
	init();
		
	if (n<=1000 && m<=1000) work1();
	//else if (flag) work2();
	
	//work2();
	return 0;
}
