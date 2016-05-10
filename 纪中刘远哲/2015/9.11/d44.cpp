#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 2*1e5+5 , M = 1e5+5;
int x1,y1,x2,y2,n,m;
LL dis[3][N],q[M][3],h[4*N];

LL dist(int x1,int y1,int x2,int y2)
{
	int r1=x1-x2 , r2=y1-y2;
	LL ret = (LL)r1*r1+(LL)r2*r2;
	return ret;
}

bool cmp1(int a[3],int b[3])
{
	return (a[1]<b[1] || (a[1]=b[1] && a[2]<b[2]));
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
	h[x] = h[x+x]+h[x+x+1];
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
		return ret1+ret2;
	}
}

int main()
{
	freopen("supply.in","r",stdin);
	//freopen("supply.out","w",stdout);

	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		dis[0][i] = i;
		dis[1][i] = dist(x,y,x1,y1);
		dis[2][i] = dist(x,y,x2,y2);
	}
	for (int i=1;i<=m;i++)
	{
		int r1,r2;
		scanf("%d%d",&r1,&r2);
		q[i][0] = i;
		q[i][1] = r1*r1;
		q[i][2] = r2*r2;
	}
	sort(dis + 1,dis + 1 + n,cmp1);
	//sort(q + 1,q + 1 + m,cmp1);

	
	int j = 0;
	for (int i=1;i<=m;i ++)
	{
		while (j+1<=n && dis[j+1][1]<=q[i][1])
		{
			j ++;
			change(1,1,maxx,dis[j][2],1);
		}
		int ans = query(1,1,maxx,1,q[i][2]);
		printf("%d\n",ans);
	}
	
	return 0;
}

