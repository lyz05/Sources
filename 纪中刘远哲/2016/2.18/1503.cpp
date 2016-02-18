#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

const int N = 50005,mo = 300;
int d[N],f[N];
int ans,n,m;
//map <int,int> p[N];
//int p[N][mo];

int gf(int x)
{
	if (f[x]==x) return x;
	int t = gf(f[x]);
	(d[x] += d[f[x]])%=mo;
	f[x] = t;
	return t;
	/*
			p[f[y]][d[y]] --;
			f[y] = a;
			d[y] = (dis-d[b]+mo)%mo;
			if (p[f[y]][d[y]]) ans ++;
			p[f[y]][d[y]] ++;
	*/
}

int main()
{
	freopen("1503.in","r",stdin);
	//freopen("1503.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) f[i] = i;
	for (int i=1;i<=m;i ++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		int x = gf(a),y = gf(b);
		if (x==y)
		{
			if ((d[b]-d[a]+mo)%mo!=dis) ans ++;	
		}
		else 
		{

			f[y] = a;
			d[y] = (dis-d[b]+mo)%mo;
		}
	}
	printf("%d\n",ans);
	return 0;
}
