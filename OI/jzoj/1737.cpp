#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N=100005,M=200005;
int n,tot,ans;
int g[N],h[N];
int v[M],w[M],next[M];
int f[N][2][4],id[N][2][3];

void add(int x,int y,int z)
{
	v[++tot]=y;
	w[tot]=z;
	next[tot]=g[x];
	g[x]=tot;
}

void dfs(int x,int y)
{
	for(int i=g[x];i;i=next[i])
	{
		if (v[i]==y) continue;
		dfs(v[i],x);
		h[x]=max(h[x],h[v[i]]);
		if (h[v[i]]>f[x][0][1])
		{
			f[x][0][2]=f[x][0][1];
			f[x][0][1]=h[v[i]];
			id[x][0][1]=v[i];
		} 
		else if (h[v[i]]>f[x][0][2]) f[x][0][2]=h[v[i]];
		int t=f[v[i]][1][1]+w[i];
		if (t>f[x][1][1])
		{
			f[x][1][3]=f[x][1][2];
			f[x][1][2]=f[x][1][1];
			f[x][1][1]=t;
			id[x][1][2]=id[x][1][1];
			id[x][1][1]=v[i];
		}
		else if (t>f[x][1][2])
		{
			f[x][1][3]=f[x][1][2];
			f[x][1][2]=t;
			id[x][1][2]=v[i];
		}
		else if (t>f[x][1][3]) f[x][1][3]=t;
	}
	h[x]=max(f[x][1][1]+f[x][1][2],f[x][0][1]);
}

void work(int x,int fa,int y,int z)
{
	int t1,t2,t3;
	if (x!=1) ans=max(ans,h[x]+y);
	for(int i=g[x]; i; i=next[i])
	{
		if  (v[i]==fa) continue;
		if  (v[i]==id[x][1][1])
		{
			t1 = f[x][1][2];
			t2 = f[x][1][2] + f[x][1][3];
		} else
		{
			t1 =f[x][1][1];
			if (v[i]==id[x][1][2]) t2 = f[x][1][1] + f[x][1][3];
			else t2 = f[x][1][1] + f[x][1][2];
		}
		if (v[i]==id[x][0][1]) t3 = f[x][0][2]; else t3 = f[x][0][1];
		work(v[i],x,max(max(max(y,t3),t1+z),t2),max(z,t1)+w[i]);
	}
}

int main()
{
	freopen("1737.in","r",stdin);
	scanf("%d\n",&n);
	
	for(int i=1; i<n; i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	work(1,0,0,0);
	
	printf("%d\n",ans);
	return 0;
}

