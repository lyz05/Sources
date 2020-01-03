#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 10005,M = 100005,mo = 1e9;
typedef long long LL;
int e[2][N],next[2][M],to[2][M],rd[N];
int dfn[N],low[N],col[N],flag[N],stack[N],tot[2];
int n,m,Index,top,ctot,S,T;
LL ans[N];
bool instack[N],flag1;
queue <int> list;

void add(int x,int y,int kind)
{
	tot[kind] ++;
	to[kind][tot[kind]] = y;
	next[kind][tot[kind]] = e[kind][x];
	e[kind][x] = tot[kind];
}

void tarjan(int x,int kind)
{
	dfn[x] = low[x] = ++ Index;
	instack[x] = 1;
	stack[++ top] = x;
	for (int i=e[kind][x];i;i=next[kind][i])
	{
		int y = to[kind][i];
		if (col[y]) continue;
		if (instack[y]) low[x] = min(low[x],dfn[y]);
		else {tarjan(y,kind);low[x]=min(low[x],low[y]);}
	}
	if (dfn[x]==low[x])
	{
		int y,num=0;
		ctot ++;
		do
		{
			y = stack[top --];
			instack[y] = 0;
			col[y] = ctot;
			num ++;
		} while (y!=x);
		if (num!=1) flag[ctot] = 1;
	}
}

void top_sort(int kind)
{
	ans[S] = 1;
	for (int i=1;i<=ctot;i ++)
		if (rd[i] == 0) 
			list.push(i);
	while (!list.empty())
	{
		int x = list.front();list.pop();
		for (int i=e[kind][x];i;i=next[kind][i])
		{
			int y = to[kind][i];
			if (ans[y]+ans[x]>=mo) flag1 = 1;
			(ans[y] += ans[x])%=mo;
			flag[y] |= flag[x];
			rd[y] --;
			if (!rd[y]) list.push(y);
		}
	}
}

int main()
{
	freopen("1238.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&m);
	S = 1,T = 2;
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,0);
	}
	tarjan(1,0);
	for (int j=1;j<=n;j ++)
		for (int i=e[0][j];i;i=next[0][i])
		{
			int u = j,v = to[0][i];
			if (col[u]!=col[v])
			{
				add(col[u],col[v],1);
				rd[col[v]] ++;
			}
		}
	//¹¹ÔìÐÂÍ¼
	S = col[S],T = col[T];
	if (S==T) 
	{
		printf("INF\n");
		return 0;
	}
	top_sort(1);
	if (flag[T]) printf("INF\n"); else
	{
		int k = 1;
		if (flag1)
			for (int i=1;i<=9;i++)
			{
				if (ans[T]/k==0) printf("0");
				k = k*10;
			}
		printf("%lld\n",ans[T]);
	}
	return 0;
}
