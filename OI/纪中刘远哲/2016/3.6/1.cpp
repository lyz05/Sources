#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 200000+5,M = 300000+5,mo = 1000000009;
typedef long long LL;
int h[N];
int n,m;
LL ans;

int gf(int x)
{
	if (x!=h[x]) h[x] = gf(h[x]);
	return h[x];
}

bool link(int x,int y)
{
	int i=gf(x), j=gf(y);
 	if (i!=j) 
	{
		h[i]=j;
		return 1;
	}else return 0;
}

int main()
{
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) h[i] = i;
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (!link(x,y)) ans = (ans*2+1)%mo;
		printf("%lld\n",ans);
	}

	return 0;
}
