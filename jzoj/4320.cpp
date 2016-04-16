#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 100000+5;
struct node
{int y,z,next;} h[2*N];
int n,k;
int e[N],vis[N];
LL a[2][N];

void add(int x,int y,int z)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].z = z;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x,LL len,int dep)
{
	int dir = (dep%2)?1:-1;
	a[dep%2][++ a[dep%2][0]]=-dir*len;
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y,z = h[i].z;
		if (vis[y]) continue;
		vis[y] = 1;
		dfs(y,len+dir*z,dep+1);
	}
}

int judge(LL x)
{
	int sum = 0;
	int r = a[1][0];
	for (int i=1;i<=a[0][0];i ++)
	{
		while (r>=1 && a[0][i]+a[1][r]>x) r--;
		sum += r;
		if (sum>k) return sum;
	}
	return sum;
}

LL half()
{
	LL ret = 0;
	LL l=a[0][1]+a[1][1],r=a[0][a[0][0]]+a[1][a[1][0]];
	while (l<=r)
	{
		LL mid = (l+r)>>1;
		if (judge(mid)>=k)
		{
			r = mid - 1;
			ret = mid;
		} else	l = mid + 1;
	}
	return ret;
}

int main()
{
	freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);

	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	vis[1] = 1;
	dfs(1,0,1);
	sort(a[0]+1,a[0]+1+a[0][0]);
	sort(a[1]+1,a[1]+1+a[1][0]);
	if (half()) printf("%lld\n",half()); else puts("Stupid Mike");
	return 0;
}

