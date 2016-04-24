#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
typedef long long LL;
struct City
{
	int h,num;
	bool operator < (const City rhs) const
	{
		return h<rhs.h;
	}
}h[maxn];
set<City> S;
set<City>::iterator it;
int n,x0,m,next[maxn][2],dist[maxn][2],g[maxn][21];
LL f[maxn][21][2];
inline void update(City x,City y)
{
	if(!next[x.num][0])
	{
		next[x.num][0]=y.num;
		dist[x.num][0]=abs(x.h-y.h);
	}
	else if(abs(x.h-y.h)<dist[x.num][0]||(abs(x.h-y.h)==dist[x.num][0]&&y.h<h[next[x.num][0]].h))
	{
		next[x.num][1]=next[x.num][0];
		dist[x.num][1]=dist[x.num][0];
		next[x.num][0]=y.num;
		dist[x.num][0]=abs(x.h-y.h);
	}
	else if(abs(x.h-y.h)<dist[x.num][1]||(abs(x.h-y.h)==dist[x.num][1]&&y.h<h[next[x.num][1]].h))
	{
		next[x.num][1]=y.num;
		dist[x.num][1]=abs(x.h-y.h);
	}
	else if(!next[x.num][1])
	{
		next[x.num][1]=y.num;
		dist[x.num][1]=abs(x.h-y.h);
	}
	return;
}
inline void query(int s,int x,LL& dista,LL& distb)
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
int main()
{
	freopen("1780.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i].h);
		h[i].num=i;
	}
	for(int i=n;i;i--)
	{
		S.insert(h[i]);
		it=S.find(h[i]);
		if(it!=S.begin())
		{
			it--;
			update(h[i],*it);
			if(it!=S.begin())
			{
				it--;
				update(h[i],*it);
				it++;
			}
			it++;
		}
		if((++it)!=S.end())
		{
			update(h[i],*it);
			if((++it)!=S.end())
				update(h[i],*it);
			it--;
		}
		it--;
	}
	for(int i=1;i<=n;i++)
	{
		g[i][0]=next[next[i][1]][0];
		f[i][0][0]=dist[i][1];
		f[i][0][1]=dist[next[i][1]][0];
	}
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
		{
			g[i][j]=g[g[i][j-1]][j-1];
			f[i][j][0]=f[i][j-1][0]+f[g[i][j-1]][j-1][0];
			f[i][j][1]=f[i][j-1][1]+f[g[i][j-1]][j-1][1];
		}
	scanf("%d",&x0);
	int s0=0;
	LL a=1e15,b=0;
	for(int i=1;i<=n;i++)
	{
		LL dista=0,distb=0;
		query(i,x0,dista,distb);
		if(distb&&(!s0||a*distb>b*dista))
		{
			s0=i;
			a=dista;
			b=distb;
		}
	}
	printf("%d\n",s0);
	scanf("%d",&m);
	while(m--)
	{
		int s,x;
		scanf("%d%d",&s,&x);
		LL dista=0,distb=0;
		query(s,x,dista,distb);
		printf("%lld %lld\n",dista,distb);
	}
	return 0;
}
