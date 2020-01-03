#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 1000+5;
int n,k,p,tot;
int a[N][N],c[N],b[N],vis[N];

int lowbit(int x)
{return x & (-x);}

void modify(int x,int delta)
{
	while (x<=n)
	{
		c[x] += delta;
		x += lowbit(x);
	}
}
int query(int x)
{
	int ret=0;
	while (x)
	{
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}

void print()
{
	for (int i=1;i<=n;i ++) printf("%d ",b[i]);
	printf("\n");
	exit(0);
}

void dfs(int dep,int tmp)
{
	if (tmp>k) return;
	if (dep>n)
	{
		if (tmp==k)
		{
			tot ++;
			if (tot==p) print();
		}
		return;
	}
	for (int i=1;i<=n;i ++)
	{
		if (vis[a[dep][i]]) continue;
		int limit = (n-dep)*(n-dep-1)/2;
		b[dep] = a[dep][i];
		int ret = b[dep]-1-query(b[dep]);
		modify(b[dep],1);
		vis[b[dep]] = 1;
		if (tmp+ret+limit>=k)
			dfs(dep+1,tmp+ret);
		vis[b[dep]] = 0;
		modify(b[dep],-1);
		b[dep] = 0;
	}
}

int main()
{
	freopen("data.in","r",stdin);
	//freopen("ocd.out","w",stdout);

	scanf("%d%d%d",&n,&k,&p);
	for (int i=1;i<=n;i ++) 
		for (int j=1;j<=n;j ++) scanf("%d",&a[i][j]);
	
	if (n<=N-5) dfs(1,0);
	printf("-1\n");
	
	return 0;
}
