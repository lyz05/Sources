#include <cstdio>
#include <vector>
using namespace std;

const int N = 1000000, P = 400000;
int n,m,p;
int x[2][P],y[2][P];
int tag[4*N],ls[4*N],rs[4*N],ms[4*N];
vector <int> add[N],del[N];

void build(int x,int l,int r)
{
	ls[x] = rs[x] = ms[x] = r-l+1;
	tag[x] = 0;
	if (l == r) return;
	int mid = (l+r)>>1;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
}


void update(int x,int l,int r)
{
	int mid = (l+r)>>1;
	if (tag[x])
	{
		ls[x] = rs[x] = ms[x] = 0;
		return;
	}
	if (l==r)
	{
		ls[x] = rs[x] = ms[x] = 1;
		return;
	}
	int lx=x+x,rx=x+x+1;
	ls[x] = ls[lx] + (ls[lx] == (mid-l+1)) * ls[rx];
	rs[x] = rs[rx] + (rs[rx] == (r-mid)) * rs[lx];
	ms[x] = max(rs[lx]+ls[rx],max(ms[lx],ms[rx]));
}

void modify(int x,int l,int r,int st,int en,int v)
{
	if (st<=l && r<=en)
	{
		tag[x] += v;
		update(x,l,r);
		return;
	}
	int mid = (l+r)>>1;
	if (st<=mid) modify(x+x,l,mid,st,en,v);
	if (en>mid) modify(x+x+1,mid+1,r,st,en,v);
	update(x,l,r);
}

int main()
{
	freopen("4238.in","r",stdin);
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=p;i ++)
	{
		scanf("%d%d%d%d",&x[0][i],&y[0][i],&x[1][i],&y[1][i]);
		add[x[0][i]].push_back(i);
		del[x[1][i]].push_back(i);
	}

	int ans = 0,root = 1;
	build(root,1,m);
	for (int i=1,j=1;i<=n;i ++)
	{
		for (int it=0;it<add[i].size();it ++)
			modify(root,1,m,y[0][add[i][it]],y[1][add[i][it]],1);
		ans = max(ans,min(i-j+1,ms[root]));
		for (;ms[root]<i-j+1;j ++)
		{
			for (int it=0;it<del[j].size();it ++)
				modify(root,1,m,y[0][del[j][it]],y[1][del[j][it]],-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}
