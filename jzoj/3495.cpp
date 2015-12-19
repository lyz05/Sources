#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 30,M = N * N ;
const double eps = 1e-6;
int n,m,st,ed;
struct point
{
	double x,y;
	point(){}
	point(double X,double Y){x=X;y=Y;}
}a[N],p[M],w[M],S,T;

int pd(double x)
{
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}

bool operator <(point a,point b)
{
	return pd(a.x-b.x)<0 || (pd(a.x-b.x)==0 && pd(a.y-b.y)<0);
}
bool operator ==(point a,point b)
{
	return pd(a.x-b.x)==0 && pd(a.y-b.y)==0;
}
point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}
point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
point operator *(point a,double v){return point(a.x*v,a.y*v);}
point operator /(point a,double v){return point(a.x/v,a.y/v);}

double sqr(double x){return x*x;}
double pmul(point a,point b){return a.x*b.x+a.y*b.y;}
double R[N],dis[M][M],G[M];
bool vis[M];

void cross(int i,int j)
{
	double d2 = sqr(a[i].x-a[j].x) + sqr(a[i].y-a[j].y);
	double d1 = sqrt(d2);
	if (pd(d2-sqr(R[i]-R[j])) < 0) return;
	if (pd(d2-sqr(R[i]+R[j])) > 0) return;
	double A = (d2+sqr(R[i])-sqr(R[j]))/(2*d1);
	double C = sqrt(sqr(R[i])-sqr(A));
	point X = (a[j]-a[i]) / d1;
	point Y = point(-X.y,X.x);
	p[++ m] = (a[i]+(X*A)+(Y*C));
	p[++ m] = (a[i]+(X*A)-(Y*C));
}
bool check(int u,int v)
{
	double dis = sqrt(sqr(p[u].x-p[v].x)+sqr(p[u].y-p[v].y));
	point X = (p[v]-p[u])/dis;
	point Y = point(-X.y,X.x);
	
	int L = 0;
	for (int i=1 ; i <= n ;i ++)
	{
		double xi = pmul(a[i]-p[u],X);
		double yi = fabs(pmul(a[i]-p[u],Y));
		if (pd(R[i]-yi) < 0) continue;
		double c = sqrt(sqr(R[i])-sqr(yi));
		double l = max(xi-c,0.0),r = min(xi+c,dis);
		if (pd(l-r)>=0) continue ;
		w[++ L] = point(l,r);
	}
	sort(w+1,w+1+L);
	double la = 0.0;
	for (int i=1;i<=L;i ++)
	{
		if (pd(w[i].x - la) <= 0)
			la = max(la,w[i].y);
		else return 0;
	}
	return pd(la-dis)>=0;
}
void dij()
{
	fill(G+1,G+1+m,1e30);
	G[st] = 0;
	while (1)
	{
		int k = 1;
		for (int i=1 ; i<=m ; i++)
			if (!vis[i] && (vis[k] || G[i]<G[k])) k = i;
		if (vis[k]) break;
		vis[k] = 1;
		for (int i=1;i<=m;i ++)
		{
			if (pd(dis[k][i])<0) continue;
			G[i] = min (G[i],G[k] + dis[k][i]);
		}
	}
}

int main()
{
	freopen("circle.in","r",stdin);
	//freopen("circle.out","w",stdout);
	scanf("%d",&n);
	for (int i=1 ; i <=n ; i++)
		scanf("%lf%lf%lf",&a[i].x,&a[i].y,&R[i]);
	scanf("%lf%lf%lf%lf",&S.x,&S.y,&T.x,&T.y);
	m = 0;
	p[++m]=S;p[++m]=T;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			cross(i,j);
	sort(p+1,p+1+m);
	m = unique(p+1,p+1+m)-(p+1);
	for (int i=1 ; i<=m ; i++)
	{
		dis[i][i]=0;
		for (int j=i+1; j<=m ;j ++)
		{
			if (check(i,j))
				dis[i][j]=dis[j][i]=
					sqrt(sqr(p[i].x-p[j].x)+sqr(p[i].y-p[j].y));
			else dis[i][j]=dis[j][i]= -1;
		}
	}
	st = lower_bound(p+1,p+1+m,S)-p;
	ed = lower_bound(p+1,p+1+m,T)-p;
	dij();
	printf("%.4lf\n",G[ed]);
	
	return 0;
}

