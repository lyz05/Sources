#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000000+5,M = 1000000+5;
struct node
{
	int y,next;
} h[M];
int n,m,tot,l,r;
int e[N],list[N],rd[N];

void add(int x,int y)
{
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
	rd[y] ++;
}

int main()
{
	//freopen("mikado.in","r",stdin);
	//freopen("mikado.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	l = 1;r = 0;
	for (int i=1;i<=n;i ++) 
		if (!rd[i]) list[++ r] = i;
	while (l<=r)
	{
		int now = list[l ++];
		for (int i=e[now];i;i=h[i].next)
		{
			int y = h[i].y;
			rd[y] --;
			if (!rd[y]) list[++ r] = y;
		}
	}
	printf("%d\n",r);

	return 0;
}

