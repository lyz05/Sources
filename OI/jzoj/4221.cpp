#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200000+5;
int n,k,st,a[N],p[N];

bool dfs(int x,int from,int dep)
{
	if (x==from)
	{
		printf("%d\n%d ",dep,x);
		return 1;
	}
	if (dep>n) return 0;
	if (dfs(a[x],from,dep+1))
	{
		printf("%d ",x);
		return 1;
	}
	return 0;
}

bool dfs1(int x,int dep)
{
	if (!p[x]) 
	{
		p[x] = dep;
		if ((dep>st) && dfs1(a[x],dep+1))
		{
			printf("%d ",x);
			return 1;
		}
	} else 
	{
		k = dep - p[x];
		st = p[x];
		printf("%d\n",k);
		return 1;
	}
	return 0;
}

int main()
{
	freopen("data8.in","r",stdin);
	
	memset(p,0,sizeof p);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d",a + i);
	}
	/*
	for (int i=1;i<=n;i ++)
	{
		if (dfs(a[i],i,1)) 
		{
			printf("\n");
			return 0;
		}
	}
	*/
	dfs1(1,1);
	printf("\n");
	return 0;
}

