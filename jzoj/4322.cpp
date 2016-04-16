#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 1e5+5,M = 1e5*50+5,L = 60;
struct node
{int l,r;}h[M];
int n,tot;
LL a[N],ans;
int b[L];

void prepar(LL x)
{
	memset(b,0,sizeof b);
	while (x!=0) b[++ b[0]] = x%2,x>>=1;
}

void push(LL x)
{
	prepar(x);
	int now = 0;
	for (int i=L-1;i;i --)
	{
		if (b[i])
		{	
			if (h[now].r) now = h[now].r; else now = h[now].r = ++ tot;
		}else
		{
			if (h[now].l) now = h[now].l; else now = h[now].l = ++ tot;
		}
	}
}

LL judge(LL x)
{
	prepar(x);
	int now = 0;
	LL y = 0;
	for (int i=L-1;i;i --)
	{
		if (!b[i])
		{
			if (h[now].r) now = h[now].r,y = (y<<1)+1;
		       		else now = h[now].l,y = y<<1;
		}else
		{
			if (h[now].l) now = h[now].l,y = y<<1; 
				else now = h[now].r,y = (y<<1)+1;
		}
	}
	return x^y;
}

int main()
{
	freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
		scanf("%lld",&a[i]),push(a[i]);
	for (int i=1;i<=n;i ++)
	{	
		ans = max(ans,judge(a[i]));
	}
	printf("%lld\n",ans);
	return 0;
}
