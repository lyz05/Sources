#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 50;
int T,n,J;
int a[N],ans[15];

void print()
{
	if (!(J --)) exit(0);
	for (int i=1;i<=n;i ++) printf("%d",a[i]);
	for (int i=2;i<=10;i ++) printf(" %d",ans[i]);
	puts("");
}

LL get(int base)
{
	LL k = 1,ret = 0;
	for (int i=n;i>=1;i --)
	{
		ret += a[i]*k;		
		k = k*base;
	}
	return ret;
}


void dfs(int dep)
{
	if (dep==n)
	{
		//dep = n;
		
		for (int i=2;i<=10;i ++)
		{
			LL now = get(i);
			bool flag = 0;
			for (int j=2;j<=sqrt(now);j ++)
				if (now%j==0) 
				{
					ans[i] = j;
					flag = 1;
					break;
				}
			if (!flag) return;
		}
		print();
		
		return;
	}
	for (int i=0;i<2;i ++)
	{
		a[dep] = i;
			dfs(dep+1);
		a[dep] = 0;
	}
}




int main()
{
	//freopen("3.in","r",stdin);
	//freopen("3.out","w",stdout);
	
	scanf("%d",&T);
	for (int i=1;i<=T;i ++)
	{
		printf("Case #%d:\n",i);
		scanf("%d%d",&n,&J);
		a[1] = 1;a[n] = 1;
		dfs(2);
	}
	return 0;
}
