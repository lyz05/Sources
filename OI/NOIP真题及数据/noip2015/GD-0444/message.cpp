#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 200000+5;
struct node
{int y,next;} h[N];
int n,ans,cnt,Time,top,ctot;
int e[N],col[N],dfn[N],low[N],stack[N];
bool instack[N];

void add(int x,int y)
{
	static int tot;
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

void tarjan(int x)
{
	dfn[x] = low[x] = ++ Time;
	instack[x] = 1;
	stack[++ top] = x;
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y;
		if (col[y]) continue;
		if (instack[y]) {low[x] = min(low[x],dfn[y]);}
		else {tarjan(y);low[x] = min(low[x],low[y]);}
	}
	if (low[x]==dfn[x])
	{
		cnt = 0;
		ctot ++;
		do
		{
			instack[stack[top]] = 0;
			col[stack[top --]] = ctot;
			cnt ++;
		} while (low[stack[top]]!=dfn[stack[top]] || stack[top]==x);
		if (cnt!=1) ans = min(ans,cnt);
	}
}

int main()
{
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		int x;
		scanf("%d",&x);add(i,x);
	}
	ans = 1e9+7,Time = 0,ctot = 0,top = 0;
	for (int i=1;i<=n;i ++)
		if (!col[i]) 
			tarjan(i);
	printf("%d\n",ans);
	return 0;
}

