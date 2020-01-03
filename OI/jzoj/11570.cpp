#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 101;
struct point
{
	int x,y;
};

point vertex[N],insd[N];
int n,m,s1,s2,T;
int out[N][N],online[N][N];

int area(point a,point b,point c)
{
	return labs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));
}

int mul(point a,point b,point c)
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

void prepar()
{
	memset(out,0,sizeof out);
	memset(online,0,sizeof online);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
	if (i!=j)
		for (int k=1;k<=m;k ++)
		{
			int tmp = mul(insd[k],vertex[j],vertex[i]);
			if (tmp>=0) out[i][j]++;
			if (tmp==0) online[i][j] = 1;
		}	
}

void dp()
{
	int a[N],tmp,max = 0;
	for (int u=1;u<=n-2;u ++)
	{
		memset(a,0,sizeof a);
		for (int i=u+1;i<=n-1;i ++)
		for (int j=i+1;j<=n;j ++)
		if (out[u][i]+out[i][j]+out[j][u]==m)
		{
			tmp = area(vertex[u],vertex[i],vertex[j]);
			if (tmp>a[j]) a[j] = tmp;
			if (online[u][i] == 0)
			{
				tmp += a[i];
				if (tmp>a[j]) a[j] = tmp;
			}
		}
		for (int j=u+2;j<=n;j ++)
			if (a[j]>max) max = a[j];
	}
	if (max==0) printf("die\n");
	else printf("%.2lf\n",max/2.0);
}

int main()
{
	freopen("1157.in","r",stdin);
	//freopen("1157.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
		scanf("%d%d",&vertex[i].x,&vertex[i].y);
	for (int i=2;i<n;i ++)
		s1 += area(vertex[1],vertex[i],vertex[i+1]);
	scanf("%d",&T);
	for (int i=1;i<=T;i ++)
	{
		scanf("%d%d",&insd[0].x,&insd[0].y);
		s2 = 0;
		for (int j=1;j<=n;j ++)
			s2 += area(insd[0],vertex[j],vertex[j%n+1]);
		if (s1 == s2) insd[++ m] = insd[0];
	}
	prepar();
	dp();

	return 0;
}
