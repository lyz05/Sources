#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<list>
#include<time.h>

using namespace std;

const int N=250000+5,inf=1e9;

struct data
{
	int m,p,r;
	long long dis;
} a[N];

struct node
{
	int num;
	long long m;
} h[4*N];

int n,point[N];
list <int> stack;

long long sqr(int x)
{
	return (long long)x*x;
}

void init()
{
	int sx,sy;
	scanf("%d %d %d %d %d",&sx,&sy,&a[0].p,&a[0].r,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d %d %d %d %d",&x,&y,&a[i].m,&a[i].p,&a[i].r);
		a[i].dis=sqr(x-sx)+sqr(y-sy);
	}

}

void build(int x,int l,int r)
{
	if (l==r) 
	{
		h[x].m=a[l].m;
		h[x].num=l;
		point[l]=x;
		return;
	}
	int mid=(l+r)>>1;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	if (h[x*2].m>h[x*2+1].m) 
		h[x]=h[x*2+1]; else h[x]=h[x*2];	
}

bool cmp(data x,data y)
{
	return x.dis<y.dis;
}

void prepar()
{
	sort(a+1,a+1+n,cmp);
	build(1,1,n);
	stack.push_back(0);
}

int select(long long num)
{
	int l=1,r=n,ans=-1;
	int mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (a[mid].dis<=num) {
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	return ans;
}

int search(int x,int l,int r,int st,int en)
{
	if (l==st && r==en) return h[x].num;
	int mid=(l+r)>>1;
	if (en<=mid) return search(x*2,l,mid,st,en);
	if (mid<st) return search(x*2+1,mid+1,r,st,en);
	int k1,k2;
	k1=search(x*2,l,mid,st,mid);
	k2=search(x*2+1,mid+1,r,mid+1,en);
	return (a[k1].m<a[k2].m)?k1:k2;
}

void up(int x)
{
	while (x!=1)
	{
		x>>=1;
		h[x] = (h[x*2].m < h[x*2+1].m) ? h[x*2] : h[x*2+1];
	}
}

void work()
{
	int ans=0;
	while (!stack.empty())
	{
		int now=stack.front();
		stack.pop_front();
		int r=select(sqr(a[now].r));
		if (r<=0) continue;
		int k=search(1,1,n,1,r);
		while (k>0 && a[k].m<=a[now].p)
		{
			ans++;
			stack.push_back(k);
			h[point[k]].m=a[k].m=inf;
			up(point[k]);
			k=search(1,1,n,1,r);
		}
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("3974.in","r",stdin);
	clock_t begin,end;
	begin=clock();
	
	init();
	prepar();
	work();
	
	end=clock();
	printf("%dms",(end-begin));
	return 0;
}
