#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 10005,M = 100005;
struct node
{
	int u,v,w;
} a[M];
int n,m;
int h[N],vis[N];
LL ans;

bool cmp(node A,node B)
{
	return A.w>B.w;
}

int gf(int x)
{
	if (x==h[x]) return x;
	else return h[x] = gf(h[x]);
}

bool link(int x,int y)
{
	int i = gf(x),j = gf(y);
	if (i==j) return 0;
	else 
	{
		h[i] = j;
		return 1;
	}
}

void prepar()
{
	memset(vis,0,sizeof vis);
	for (int i=0;i<n;i ++)
		h[i] = i;
	ans = 0;
}

int main()
{
	//freopen("1030.in","r",stdin);
	//freopen(".out","w",stdout);

	while (1)
	{
		scanf("%d%d",&n,&m);
		if (n==0 && m==0) return 0;
		prepar();
		for (int i=1;i<=m;i ++) 
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		sort(a+1,a+1+m,cmp);
		for (int i=1;i<=m;i ++)
		{
			int x = gf(a[i].u),y = gf(a[i].v),z = a[i].w;
			if (x!=y)
			{
				if (vis[x] && vis[y]) continue;
				if (vis[x] || vis[y]) vis[x]=vis[y]=1;
				ans += z;
				link(x,y);
			} else if (!vis[x])
			{
				vis[x] = 1;
				ans += z;
				link(x,y);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
