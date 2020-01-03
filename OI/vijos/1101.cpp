#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 305;
struct node
{
	int y,next;
} h[2*N];
int n,m,tot,tmp,ans;
int e[N],dep[N],a[N],num[N],fa[N];
bool vis[N];

bool cmp(int x,int y)
{
	return dep[x]<dep[y];
}

void add(int x,int y)
{
	h[++ tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x)
{
	a[++ a[0]] = x;
	num[x] = 1;
	for (int i=e[x];i;i=h[i].next)
	{
		int y = h[i].y;
		if (!vis[y])
		{
			vis[y] = 1;
			fa[y] = x;
			dep[y] = dep[x] + 1;
			dfs(y);
			num[x] += num[y];
		}
	}
}

void search(int deep,int last)
{
	int next = 0;
	ans = max(tmp,ans);
	if (last>a[0]) return;

	for (next=last;next<=a[0] && dep[a[next]]==deep;next ++);
	for (int i=last;i<next;i ++)
		if (vis[fa[a[i]]]) 
			vis[a[i]] = 1;
	for (int i=last;i<next;i ++)
	{
		if (vis[a[i]]) continue;
		tmp += num[a[i]];
		vis[a[i]] = 1;
		search(deep+1,next);
		vis[a[i]] = 0;
		tmp -= num[a[i]];
	}
	for (int i=last;i<next;i ++)
		if (vis[fa[a[i]]]) 
			vis[a[i]] = 0;
}

int main()
{
	//freopen("1101.in","r",stdin);
	//freopen("1101.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dep[1] = 1;vis[1] = 1;
	dfs(1);
	sort(a+1,a+1+a[0],cmp);
	memset(vis,0,sizeof vis);
	search(2,2);
	printf("%d\n",n-ans);
	return 0;
}
