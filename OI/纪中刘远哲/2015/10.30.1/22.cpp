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
int n,l,r,tot;
bitset<N> ans[N];
bitset<N> p[N];
map <int,int> ha;

int main()
{
	freopen("walk.in","r",stdin);
	//freopen("walk.out","w",stdout);

	scanf("%d",&n);
	l = 1e9+7;r = 0;
	for (int i=1;i<=n;i ++)
	{
		scanf("%d%d%d",&a[i].t,&a[i].u,&a[i].v);
		l = min(l,min(a[i].u,a[i].v));
		r = max(r,max(a[i].u,a[i].v));
	}

	for (int j=l;j<=r;j ++)
	{
		tot = 0;
		ha.clear();
		for (int i=1;i<=n;i ++) p[i].reset();
		for (int i=1;i<=n;i ++)
		{
			if ((a[i].u<=j && j<=a[i].v) ||
				(a[i].v<=j && j<=a[i].u))
			{
				int Time = abs(j-a[i].u)+a[i].t,
				    id = ha[Time];
				if (!id) id = ++ tot;
				p[id][i] = 1;
				ha[Time] = id;
			}
		}
		for (int i=1;i<=n;i ++)
		{
			if ((a[i].u<=j && j<=a[i].v) ||
				(a[i].v<=j && j<=a[i].u))
			{
				int Time = abs(j-a[i].u)+a[i].t;
				ans[i] |= p[ha[Time]];
				ans[i][i] = 0;
			}
		}
	}
	for (int i=1;i<=n;i ++) printf("%d ",ans[i].count());
	puts("");

	return 0;
}
