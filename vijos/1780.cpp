#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 100000+5,M = 10000+5;
struct City
{
	int h,id;
	bool operator < (const City &A) const
	{
		return h<A.h;
	}
} city[N];
struct Link
{
    int nxt,pre;
}link[N];
int n,m,x0;
int next[N][2],dist[N][2],g[N][21],h[N],idx[N];
LL f[N][21][2];

void update(int i,int j)		//更新距离x最近与次近的城市
{
	if (j==0) return;
	City x = city[i],y = city[j];
	if(!next[x.id][0])
	{
		next[x.id][0]=y.id;
		dist[x.id][0]=abs(x.h-y.h);
	}
	else if(abs(x.h-y.h)<dist[x.id][0]||(abs(x.h-y.h)==dist[x.id][0]&&y.h<h[next[x.id][0]]))
	{
		next[x.id][1]=next[x.id][0];
		dist[x.id][1]=dist[x.id][0];
		next[x.id][0]=y.id;
		dist[x.id][0]=abs(x.h-y.h);
	}
	else if(abs(x.h-y.h)<dist[x.id][1]||(abs(x.h-y.h)==dist[x.id][1]&&y.h<h[next[x.id][1]]))
	{
		next[x.id][1]=y.id;
		dist[x.id][1]=abs(x.h-y.h);
	}
	else if(!next[x.id][1])
	{
		next[x.id][1]=y.id;
		dist[x.id][1]=abs(x.h-y.h);
	}
	
}

void query(int s,int x,LL &dista,LL &distb)
{
	for(int i=20;i>=0;i--)
		if(f[s][i][0]+f[s][i][1]<=x&&g[s][i])
		{
			dista+=f[s][i][0];
			distb+=f[s][i][1];
			x-=f[s][i][0]+f[s][i][1];
			s=g[s][i];
		}
	if(next[s][1]&&dist[s][1]<=x)
		dista+=dist[s][1];
}

bool cmp(City A,City B)
{
	return A.id<B.id;
}

int main()
{
	freopen("1780.in","r",stdin);
	//freopen("1780.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d",&city[i].h);
		h[i] = city[i].h;
		city[i].id = i;
	}
	sort(city+1,city+1+n);
	for (int i=1;i<n;i ++) 
	{
		link[i].nxt = i+1;
		link[i+1].pre = i;
		idx[city[i].id] = i;
	}
	idx[city[n].id] = n;

	//sort(city+1,city+1+n,cmp);
	for (int i=1;i<=n;i ++)			//双向链表,预处理每个城市的后,最近与次近的城市
	{
		int id = idx[i];
		update(id,link[id].pre);
		update(id,link[link[id].pre].pre);
		update(id,link[id].nxt);
		update(id,link[link[id].nxt].nxt);
		if (link[id].nxt) link[link[id].nxt].pre = link[id].pre;
		if (link[id].pre) link[link[id].pre].nxt = link[id].nxt;
	}
	for (int i=1;i<=n;i ++)			//倍增
	{
		g[i][0] = next[next[i][1]][0];
		f[i][0][0] = dist[i][1];
		f[i][0][1] = dist[next[i][1]][0];
	}
	for (int j=1;j<=20;j ++)
	{
		for (int i=1;i<=n;i ++)
		{
			g[i][j] = g[g[i][j-1]][j-1];
			for (int k=0;k<2;k ++)
			f[i][j][k] = f[i][j-1][k]+f[g[i][j-1]][j-1][k];
		}
	}
	scanf("%d",&x0);
	int a=1e9+7,b = 0,ans = 0;
	for (int i=1;i<=n;i ++)
	{
		LL dista=0,distb=0;
		query(i,x0,dista,distb);
		if (distb && (!ans || a*distb>b*dista || (a*distb==b*dista && h[ans]<h[i])))
		{
			ans = i;
			a = dista;
			b = distb;
		}
	}
	printf("%d\n",ans);
	scanf("%d",&m);
	while (m --)
	{
		int s,x;
		scanf("%d%d",&s,&x);
		LL dista=0,distb=0;
		query(s,x,dista,distb);
		printf("%lld %lld\n",dista,distb);
	}
	return 0;
}
//O(N log N+N+20N+20M)
