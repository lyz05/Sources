#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 1e6+10;
struct node
{
	int y,next;
} h[2*N];
LL a[N],b[N];
int e[N];
int n,tot;
LL ans;

void add(int x,int y)
{
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

int half(int l,int r,LL m)
{
	int ret=0;
	while (l<=r)
	{
		int mid = (l+r)>>1;
		if (m>=b[mid])
		{
			ret = mid;
			l = mid + 1;
		} else 	r = mid - 1;
	}
	return ret+1;
}

void dfs(int x)
{
	if (x==n+1)
	{
		if (ans<b[0])
		{
			ans = b[0];
		}
		return;
	}
	ans = max(ans,b[0]);
	int ret;
	LL b0;
	ret = half(1,b[0],a[x]);
	for (int i=e[x];i;i=h[i].next)
	{
			b0 = b[ret];
			b[ret] = a[x];
			if (ret>b[0]) b[0] = ret;
				dfs(h[i].y);
			b[ret] = b0;
			if (b[ret]==0) b[0] = ret-1;
	}
}

int main()
{
	freopen("cicada.in","r",stdin);
	//freopen("cicada.out","w",stdout);

	scanf("%d",&n);
	for (int i=2;i<=n;i ++)
	{
		int x;
		scanf("%d",&x);
		add(x,i);
	}
	for (int i=1;i<=n;i ++) if (!e[i]) add(i,n+1);
	for (int i=1;i<=n;i ++) scanf("%lld",a+i);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

