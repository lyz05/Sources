#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <bitset>
using namespace std;

const int N = 1000+5;
struct node
{int t,u,v;} a[N];
int n,ans[N];
int s5,s6;

bool judge(int x1,int y1,int x2,int y2)
{
	if (x1>y1) swap(x1,y1);
	if (x2>y2) swap(x2,y2);
	if (x1<=x2 && y2<=y1) {s5=x2;s6=y2;return 1;}
	if (x2<=x1 && y1<=y2) {s5=x1;s6=y1;return 1;}
	if (x1<=x2 && x2<=y1 && y1<=y2) {s5=x2,s6=y1;return 1;}
	if (x2<=x1 && x1<=y2 && y2<=y1) {s5=x1,s6=y2;return 1;}
	return 0;
}

bool judge1(int x1,int y1,int x2,int y2)
{
	if (x1>=y1 && x2>=y2) return 1;
	if (x1<=y1 && x2<=y2) return 1;
	return 0;
}
int main()
{
	freopen("walk.in","r",stdin);
	//freopen("walk.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d%d%d",&a[i].t,&a[i].u,&a[i].v);
	}

	for (int i=1;i<=n;i ++)
	{
		for (int j=i+1;j<=n;j ++)
		{
			int s1 = a[i].u,s2 = a[i].v,
			    s3 = a[j].u,s4 = a[j].v;
			if (judge(s1,s2,s3,s4))
			{
				if (judge1(s1,s2,s3,s4))
				{
					int T1 = abs(s5-s1)+a[i].t,
					    T2 = abs(s5-s3)+a[j].t;
					if (T1==T2) ans[i]++,ans[j]++;
				} else 
				{
					int T1 = abs(s5-s1)+a[i].t,
					    T2 = abs(s6-s1)+a[i].t,
					    T3 = abs(s5-s3)+a[j].t,
					    T4 = abs(s6-s3)+a[j].t;
					if (T1>T2) 
						swap(T1,T3),swap(T2,T4);
					int x = (T2+T4)/2,y = (T2+T4)%2;
					if (T1<=x&&x<=T2&&T3>=x&&x>=T4)
						ans[i]++,ans[j]++;
				}
			}
		}
	}
	for (int i=1;i<=n;i ++) printf("%d ",ans[i]);
	puts("");
	return 0;
}
