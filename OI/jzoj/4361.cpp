#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5+6,M = 1e5+6;
struct Edge
{int y,next,w;
double p;
}h[N+M];
struct node
{double x,y;
}a[N+M];
int n,m,tot,e[N];
double f[N];

void add(int x,int y,double p,int w)
{
	h[++ tot].y = y;
	h[tot].p = p;
	h[tot].w = w;
	h[tot].next = e[x];
	e[x] = tot;
}

bool cmp(node A,node B)
{
	return (A.x+A.y*B.x)>(B.x+B.y*A.x);
}

int main()
{
	freopen("4361.in","r",stdin);
	//freopen("4361.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i ++)
	{
		int z;
		scanf("%d",&z);
		add(i,i+1,1,z);
	}
	for (int i=1;i<=m;i ++)
	{
		int x,y,w;double p;
		scanf("%d%d%lf%d",&x,&y,&p,&w);
		add(x,y,p,w);
	}

	f[n] = 0;
	for (int x=n;x;x --)
	{
		tot = 0;
		for (int i=e[x];i;i = h[i].next)
		{
			a[++ tot].x = f[h[i].y]*h[i].p+h[i].w;
			a[tot].y = (1-h[i].p);
		}
		sort(a+1,a+1+tot,cmp);
		for (int i=1;i<=tot;i ++)
			f[x] = a[i].x+a[i].y*f[x];
	}
	printf("%.2f\n",f[1]);
	return 0;
}
