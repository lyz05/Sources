#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 50;
int n,tmp,ans,a[N],cnt,b[1000][N];

void dfs(int dep,int st)
{
	if (dep>n)
	{
		if (abs(tmp)<ans)
		{
			ans = abs(tmp);
			cnt = 0;
		} 
		if (abs(tmp)==ans)
		{
			int conan = 1;
			memcpy(b[++ cnt],a,sizeof a);
		}
		return;
	}
	for (int i=-1;i<=1;i += 2)
	{
		a[dep] = i;
		tmp += i*dep*dep;
			dfs(dep+1,i);
		tmp -= i*dep*dep;
		a[dep] = 0;
	}
}

int main()
{
	//freopen("five.in","r",stdin);
	//freopen("five.out","w",stdout);

	ans = 1e9+7;
	scanf("%d",&n);
	dfs(1,0);
	printf("%d %d\n",ans,cnt);
	int i = 1;
//	for (i=1;i<=cnt;i ++)
//	{
		for (int j=1;j<=n;j ++)
			printf("%d\t",b[i][j]);
		puts("");
//	}
	return 0;
}

