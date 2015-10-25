#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 10002,M = 50002, K = 5+2;
const LL oo=1LL<<60LL;
struct node
{
	int y,w,next;
} h[2*M];

int st[K],e[N],n,m,k,tot = 0;
bool p[N],vis[N];
LL tmp,ans,d[K][N];

void spfa(int s,int *d)
{
	queue <int> q;
	memset(d,124,sizeof d);
	d[s] = 0;
	memset(vis,0,sizeof vis);
	
	q.push(s); vis[s] = 1;
	while (!q.empty())
	{
		int x;
		x = q.front();q.pop();vis[x] = 0;
		for (int k=e[x];k;k = h[k].next)
		{
			int y = h[k].y;
			if (d[x]+h[k].w < d[y])
			{
				d[y] = d[x] + h[k].w;
				if (!vis[y])
				{
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
	
}

int work(int x)
{
	vis[st[x]] = 1;
	LL ret = oo;
       	int ID = 0;
	for (int i=1;i<=k;i++)
		if (!vis[st[i]] && d[x][st[i]]<ret)
			ret = d[x][st[i]] ,ID = i;
	if (ID==0) return x;
	tmp += ret;
	return work(ID);
}

void add(int x,int y,int z)
{
	tot ++;
	h[tot].y = y;
	h[tot].w = z;
	h[tot].next = e[x];
	e[x] = tot;
}

int judge()
{
	
}

int main()
{
	freopen("2933.in","r",stdin);
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d",st + i);
		p[st[i]] = 1;
	}
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for (int i=1;i<=k;i++) spfa(st[i],d[i]);
	ans = oo;
	for (int i=1;i<=n;i++)
		if (!p[i])
		{
			memset(vis,0,sizeof vis);
			LL ret = oo;
			int ID = 0;
			tmp = 0;
			for (int j=1;j<=k;j++) 
				if (d[j][i]<ret) 
					ret = d[j][i] , ID = j;
			tmp += ret;
			tmp += d[work(ID)][i];
			ans = min(ans,tmp);
		}

	printf("%lld\n",ans);
}
