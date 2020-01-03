#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const LL oo = (LL)1<<60;
int T,lim;
LL ans;

void work(LL l,LL r)
{
	if (l==0)
	{	
		ans = min(ans, r);
		return;
	}
	if (l<0 || r>lim) return;
	if (r>ans) return;
	if (r-l+1>l) return;
	//if (r>ans) return;
	LL x,y;

	x = l;
	y = (r<<1) - l;
	work(x,y);
	y = (r<<1)+1 - l;
	work(x,y);

	y = r;
	x = ((l-1)<<1) - r;
	work(x,y);
	x = ((l-1)<<1)+1 - r;
	work(x,y);
}

int main()
{
	freopen("tree.in","r",stdin);//freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while (T --)
	{
		int l,r;
		scanf("%d%d%d",&l,&r,&lim);
		if (lim<r) puts("-1"); else
		if (l==0 || l==r) printf("%d\n",r);
		else 
		{
			ans = oo;
			work(l,r);
			if (ans!=oo) printf("%lld\n",ans); else puts("-1");
		}
	}
	return 0;
}
