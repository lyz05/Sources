#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1e5+5;
int n;
long long sa,sp,ans,p;

struct node
{
	int x,y;
}f[2*N];

bool operator < (node a,node b)
{
	return (a.x<b.x) || (a.x==b.x && a.y>b.y);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[i].x=x;f[i].y=1;
		f[i+n].x=y;f[i+n].y=-1;
		sa += x;
	}
	sort(f+1,f+2*n+1);
	ans=0;
	for (int i=1;i<=2*n;i++)
	{
		if (f[i].y==1)
		{
			sa -= f[i].x;
			sp ++;
		} else 
		{
			if (ans<sa+sp*f[i].x) ans=sa+sp*f[i].x,p=f[i].x;
			sp --;
		}
	}
	printf("%lld %lld\n",p,ans);

	return 0;
}
