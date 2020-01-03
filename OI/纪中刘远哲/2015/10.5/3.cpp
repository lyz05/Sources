#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5000+5;
struct node
{
	int next,y;
} h[N*N];
int a[N],b[N],p[N],vis[N],e[N];
int tot,ans,cnt,n;

void add(int x,int y)
{
	cnt ++;
	h[cnt].y = y;
	h[cnt].next = e[x];
	e[x] = cnt;	
}
void dfs(int x,int en)
{
	if (x==en)
	{
		for (int i=1;i<=b[0];i ++)
			p[b[i]] ++;
		tot ++;
		return ;
	}
	for (int i=e[x];i;i=h[i].next)
	{
		if (vis[h[i].y]) continue;
		b[++ b[0]] = h[i].y;
		vis[h[i].y] = true;
		dfs(h[i].y,en);
		vis[h[i].y] = false;
		b[b[0] --] = 0;
	}
}

int main()
{
	freopen("parade.in","r",stdin);
	//freopen("parade.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	for (int i=1;i<=n;i ++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		for (int j=i+1;j<=n;j ++)
			if (l<=a[j] && a[j]<=r) 
				add(i,j);
	}
	for (int i=1;i<=n;i ++)
	{
		memset(p,0,sizeof p);
		memset(vis,0,sizeof vis);
		tot = 0;ans = 0;
		b[0] = 1;b[1] = 1;
		dfs(1,i);
		if (tot == 0) ans = -1; else
		for (int i=1;i<=n;i ++)
			if (p[i]==tot) ans ++;
		printf("%d\n",ans);
	}

	return 0;
}
