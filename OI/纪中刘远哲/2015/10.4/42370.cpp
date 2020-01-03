#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5+5;
const LL mo = (LL)1<<32;
int n,q;
LL tmp,ans;
struct node
{int d,v;} a[N];

bool cmp(node A,node B)
{
	return A.d<B.d;
}

void work(int tot,int last,int n,int minn,int tmp)
{
	if (tot == 0)
	{
		(ans += tmp) %= mo;
		return;
	}
	for (int i = last + 1;i<=n;i ++)
	{
		if (a[i].v==minn) continue;
		work(tot-1,i,n,minn,(tmp*a[i].v)%mo);
	}
}

int half(int st)
{
	int l = 1 , r = n, ret = n + 1;
	while (l<=r)
	{
		int mid = (l+r) >> 1;
		if (a[mid].d>=st)
		{
			ret = mid;
			r = mid - 1; 
		} else	l = mid + 1;
	}
	return ret;
}

int main()
{
	//freopen("melancholy.in","r",stdin);
	//freopen("melancholy.out","w",stdout);

	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].d);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].v);
	sort(a + 1,a + 1 + n,cmp);

	while (q --)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		int l = half(x),r = half(y);
		if (a[r].d>y || r>n) r --;
		if (r-l+1<z) puts("0"); else
		{
			ans = 0;
			int minn = 1e9;
			for (int i=l;i<=r;i++) minn = min(minn,a[i].v);
			work(z,l-1,r,minn,1);

			LL ret = 1;
			for (LL i=2;i<=z;i++) (ret *= i) %= mo;
			(ans *= ret)%=mo;
	
			printf("%lld\n",ans);
		}
	}

	return 0;
}
