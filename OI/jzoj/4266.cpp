#include <cstdio>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#define pair pair<double,double>
#define mp(a,b) make_pair(a,b)
#define x first
#define y second
using namespace std;

const int N = 14, K = 25;
struct node
{
	int r,cost;
} b[K];
pair a[N];
int n,k,f[1<<N],minn;

double sqr(double x){return x*x;}
int dist(pair i,pair j)
{return sqr(i.x-j.x)+sqr(i.y-j.y);}

double make(double x1,double y1,double x2,double y2){
	if (x1==x2) return -1;
	if (y2==y1) return -2;
	return (y2-y1)/(x2-x1);
}

pair get(int id1,int id2,double r,int kind)
{
	double x1=a[id1].x,y1=a[id1].y,x2=a[id2].x,y2=a[id2].y;
	//if (x1>x2) {swap(x1,x2);swap(y1,y2);}
	
	double m1=(x1+x2)/2,m2=(y1+y2)/2;
	r=sqrt(sqr(r)-(sqr(m1-x1)+sqr(m2-y1)));
	double xl=make(x1,y1,x2,y2);
	if (xl==-1)
	{
		pair ret;
		if (kind==0) ret = mp(m1-r,m2);
		else ret = mp(m1+r,m2);
		return ret;
	}else
	if (xl==-2)
	{
		pair ret;
		if (kind==0) ret = mp(m1,m2+r);
		else ret = mp(m1,m2-r);
		return ret;
	}
	double nxl=(-1)/xl;
	double x=sqrt(r*r/(1+sqr(nxl)));
	pair ret;
	if (kind==0) ret=mp(m1-x,m2-nxl*x);
	else ret=mp(m1+x,m2+nxl*x);
	return ret;
}

int main()
{
	freopen("circle.in","r",stdin);
	//freopen("circle.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i ++) 
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[i] = mp(u,v);
	}
	minn = 1e9+7;
	for (int i=1;i<=k;i ++)
	{
		scanf("%d%d",&b[i].r,&b[i].cost);
		minn = min(minn,b[i].cost);
	}

	memset(f,124,sizeof f);
	for (int i=0;i<n;i ++) f[1<<i] = minn;
	for (int i=1;i<=n-1;i ++)
	for (int j=i+1;j<=n;j ++)
		for (int kk=1;kk<=k;kk ++)
		{
			if (dist(a[i],a[j])>4*sqr(b[kk].r)) continue;
			for (int kind=0;kind<=1;kind ++)
			{
				pair cir=get(i,j,b[kk].r,kind);
				int tmp = (1<<(i-1))|(1<<(j-1));
				for (int now=1;now<=n;now ++)
				{
					if (dist(a[now],cir)<=sqr(b[kk].r))
						tmp |= (1<<(now-1));
				}
				f[tmp]=min(f[tmp],b[kk].cost);
			}
		}
	for (int i=1;i<=(1<<n)-2;i ++)
		for (int j=1;j<=i-1;j ++)
		{
			f[i|j] = min(f[i|j],f[i]+f[j]);
		}
	printf("%d\n",f[(1<<n)-1]);
}
