#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int P = 400000+5, dir[][2] = {{0,0},{1,0},{0,1},{1,1}};
struct node
{
	int x1,y1,x2,y2;
	node(int x1=0,int y1=0,int x2=0,int y2=0):x1(x1),y1(y1),x2(x2),y2(y2){}
} a[P];
struct point
{	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
}
int n,m,p;
int ans;

bool pd(point &st)
{
	point en[4];
	for (int i=1;i<=p;i ++)
	{


	}
	return 0;
}

bool judge(int d)
{
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
		{
			bool flag = 0;
			point tmp[4]
			for (int k=0;k<4;k ++)
			{
				tmp[k].x = i+d*dir[k];
				tmp[k].y = j+d*dir[k]
			}
			for (int i=1;i<=p;i ++)
			{
				en[0].x = a[i].x1;en[0].y = a[i].y1;
				en[1].x = a[i].x2;en[1].y = a[i].y1;
				en[2].x = a[i].x1;en[2].y = a[i].y2;
				en[3].x = a[i].x2;en[3].y = a[i].y2;
				pd(tmp);
			}
			if (!flag) return 1;
		}
	return 0;
}

int main()
{
	//freopen("suquare.in","r",stdin);
	//freopen("suquare.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=p;i ++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	int l=0,r=min(n,m);
	if (p==0) printf("%d\n",r); else
	{
		while (l<=r)
		{
			int mid = (l+r) >> 1;
			if (judge(mid))
			{
				ans = mid;
				l = mid + 1;
			} else	r = mid - 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
