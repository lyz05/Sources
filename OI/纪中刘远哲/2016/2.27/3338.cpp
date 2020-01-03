#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 100000+5,INF = 1e9+7;
struct node
{
	int y,next;
} h[N*2];
int n,tot;
int e[N],a[N],ans[N];
bool vis[N];
vector <int> d[N];

void add(int x,int y)
{
	h[++ tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

int insert(int kind,int val)
{
	if (d[kind].back()<=val)
		d[kind].push_back(val);
	else 
	{
		int l = 1,r = d[kind].size()-1,mid,ans = 0;
		while (l<=r)
		{
			mid = (l+r)>>1;
			if (d[kind][mid]<=val) 
			{
				l = mid+1;
				ans = l;
			} else r = mid-1;
		}
		d[kind][++ ans] = val;
	}
	return d[kind].size()-1;
}

void dfs(int x,int &L,int &R)
{
	bool flag=0;L = INF,R = -INF;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y,l,r;
		if (!vis[y])
		{
			flag = 1;
			vis[y] = 1;
			dfs(y,l,r);
			L = min(L,l);
			R = max(R,r);
		}
	}
	if (!flag) 
	{
		d[++ tot].push_back(0);
		d[tot].push_back(a[x]);
		L = R = tot;
		ans[x] = 1;
	} else 
	{
		for (int i=L;i<=R;i ++)	
			ans[x] = max(ans[x],insert(i,a[x]));
	}
	return;
}

int main()
{
	freopen("3338.in","r",stdin);
	//freopen("3338.out","w",stdout);

	int x,y;
	scanf("%d%d",&n,&x);
	for (int i=2;i<=n;i ++)
	{
		scanf("%d",&x);
		add(i,x);add(x,i);
	}
	for (int i=1;i<=n;i ++) scanf("%d",a+i);
	vis[1] = 1; tot = 0;
	dfs(1,x,y);
	for (int i=1;i<=n;i ++) printf("%d ",ans[i]);
	puts("");
	return 0;
}
