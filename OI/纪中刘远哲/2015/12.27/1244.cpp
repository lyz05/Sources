#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 1005;
int n,m,tot;
double ans;
int h[N],x[N],y[N];

struct node
{
	int x,y;
	double z;
}e[N*(N-1)/2];

void prepar()
{
	for (int i=1;i<=n;i ++) h[i] = i;
}

int gf(int x)
{
	if (x!=h[x]) h[x] = gf(h[x]);
	return h[x];
}

void link(int x,int y,double z)
{
	int i=gf(x),j=gf(y);
	if (i!=j)
	{
		h[i] = j;
		ans += z;
	}
}

double dis(int x1,int y1,int x2,int y2)
{
	return sqrt((LL)(x1-x2)*(x1-x2)+(LL)(y1-y2)*(y1-y2));
}

bool cmp(node A,node B)
{
	return A.z<B.z;
}

void getdis()
{
	for (int i=1;i<=n;i ++)
	for (int j=i+1;j<=n;j ++)
	{
		e[++ tot].x = i,e[tot].y = j;
		e[tot].z = dis(x[i],y[i],x[j],y[j]);
	}
	sort(e+1,e+1+n*(n-1)/2,cmp);
}

int main()
{
	//freopen("1244.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&m);
	prepar();
	for (int i=1;i<=n;i ++) scanf("%d%d",x+i,y+i);
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y,0);
	}
	getdis();
	for (int i=1;i<=tot;i ++) link(e[i].x,e[i].y,e[i].z);
	printf("%.2f\n",ans);
	return 0;
}
