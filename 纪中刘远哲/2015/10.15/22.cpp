#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000;
int n,m,ans,a[N],cnt;

void dfs(int dep)
{
	if (dep>n)
	{
		ans ++;
		return;		
	}

	for (int i=1;i<=m;i ++)
	{
		if (dep!=1 && a[dep-1]==i) continue;
		if (dep==n && a[1]==i) 
		{
			cnt ++;
			continue;
		}
		a[dep] = i;
			dfs(dep+1);
		a[dep] = 0;
	}
}

int main()
{
	//freopen("mission.in","r",stdin);
	//freopen("mission.out","w",stdout);

	scanf("%d%d",&n,&m);
	dfs(1);	
	printf("%d %d\n",ans,cnt);

	return 0;
}

