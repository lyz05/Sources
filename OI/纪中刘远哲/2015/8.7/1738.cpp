#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const	int	M=30000,N=15000;
struct edge
{
	int x,y,z;
	bool operator < (edge A) const
	{
		return z<A.z;
	}
} h[M];
int n,m,k,f[N];

int gf(int x)
{
	if (x==f[x]) return x;
	int y=gf(f[x]);
	f[x]=y;
	return y;
}

void link(int x,int y)
{
	int i=gf(x),j=gf(y);
	if (i!=j) f[i]=j; 	
}

bool judge(int x,int y)
{
	int i=gf(x),j=gf(y);
	return i==j;
}

int work(int u,int v)
{
	for (int i=1;i<=n;i++)
		f[i] = i;
	for (int i=1; i <= m ; i++)
	{
		link(h[i].x,h[i].y);
		if (judge(u,v)) return h[i].z; 
	}
	return -1;
}

int main()
{
	freopen("1738.in","r",stdin);
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1 ; i <= m ; i ++)
	{
		scanf("%d%d%d",&h[i].x,&h[i].y,&h[i].z);
	}
	sort(h + 1,h + 1 + m);
	for (int i=1 ; i <= k ; i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",work(u,v));
	}
	return 0;
}

