#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 3000+5;
const LL mo = 10000000007;
int n,k,ans;
int a[N],vis[N];

void judge()
{
	int cnt = 0;
	for (int i=1;i<=n;i ++)
		for (int j=i+1;j<=n;j ++)
			if (a[i]>a[j]) cnt ++;
	if (cnt<=k) ans ++;
}

void dfs(int dep)
{
	if (dep>n)
	{
		judge();
		return;
	}
	for (int i=1;i<=n;i ++)
		if (!vis[i])
		{
			vis[i] = 1;
			a[dep] = i;
			dfs(dep+1);
			a[dep] = 0;
			vis[i] = 0;	
		}
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);

	scanf("%d%d",&n,&k);
	dfs(1);
	printf("%d\n",ans);

	return 0;
}


