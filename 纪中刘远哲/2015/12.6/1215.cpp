#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 10;
const double pi=3.1415926;
double d[N][N],r[N];
double dis,ans;
int n,flag;
int x[N],y[N];
bool vis[N];


double dist(int x,int y)
{
	return sqrt(x*x+y*y);
}

double minn(double a,double b,double c,double d)
{
	double ret1 = min(a,b),ret2 = min(c,d);
	return min(ret1,ret2);
}

void dfs()
{
	if (flag==n)
	{
		dis = max(dis,ans);
		return;
	}
	for (int i=2;i<=n+1;i ++)
	if (!vis[i])
	{
		r[i] = minn(abs(x[i]-x[0]),abs(x[i]-x[1]),abs(y[i]-y[0]),abs(y[i]-y[1]));
		for (int j=2;j<=n+1;j ++)
		if (vis[j] && j!=i)
		r[i] = min(r[i],d[i][j]-r[j]);
		if (r[i]<0) r[i] = 0;
		vis[i] = 1;
		ans += r[i]*r[i];
		flag ++;
			dfs();
		flag --;
		ans -= r[i]*r[i];
		vis[i] = 0;
		r[i] = 0;
	}
	
}

int main()
{
	freopen("1215.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&n);
	scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);
	if (n==0)
	{
		ans = abs(x[0]-x[1])*abs(y[0]-y[1]);
		printf("%.0f\n",ans);
		return 0;
	}
	for (int i=2;i<=n+1;i ++) scanf("%d%d",&x[i],&y[i]);
	for (int i=2;i<=n+1;i ++)
	for (int j=2;j<=n+1;j ++)
	if (i!=j)
		d[i][j] = dist(x[i]-x[j],y[i]-y[j]);
	dfs();
	ans = abs(x[0]-x[1])*abs(y[0]-y[1])-pi*dis;
	printf("%.0f\n",ans);
	return 0;
}
