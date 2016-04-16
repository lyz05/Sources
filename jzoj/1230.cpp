#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 50000+5;

struct node
{
	int fa,buy,sell,sb,bs;
} f[2*N];

node gf(int x)
{
	node t;
}

void tarjan(int x,int fa)
{
	for (int i=e[0][x];i;i=h[0][i].next)
	{
		if (h[i].y!=fa) 
		{
			tarjan(h[i].y,x);
			f[y].fa = x;
		}
	}
	for (int i=e[1][x];i;i=h[1][i].next)
	{
		int j = h[1][i].y,y = b[j][b[j][0]==x];//’“µΩ¡Ì“ªµ„
		if (!vis[y]) continue;
		add(f[y].fa,i,2);
	}
	for (int i=e[2][x];i;i = h[2][i].next)
	{
		int j=h[2][i].y,x=b[i][0],y=b[i][1];
		gf(x),gf(y);
		ans[i] = max(ans[i],f[x].bs);
		ans[i] = max(ans[i],f[y].sb);
		ans[i] = max(ans[i],f[y].sell-f[x].buy);
	}
}


int main()
{
	freopen("1230.in","r",stdin);
	//freopen("1230.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d",&a[i]);
		fa[i] = node(i,a[i],a[i],0,0);
	}
	for (int i=1;i<n;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,0),add(y,x,0);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i ++)
	{
		scanf("%d%d",&b[i][0],&b[i][1]);
		add(b[i][0],i,1);add(b[i][1],i,1);
	}
	tarjan(1,0);
	for (int i=1;i<=m;i ++) printf("%d\n",0);
	return 0;
}
