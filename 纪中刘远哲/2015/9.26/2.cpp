#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100000;
int f[N][4];
int n,k;
double ans;

void dfs(int dep,int cnt,int x,int y)
{
	if (dep>n)
	{
		if (cnt == k) 
			ans = max(ans,1.0*x/y);
		return;
	}
	if (cnt>k) return;
	for (int i=0;i<=1;i++)
	{
		if (!i)
		{
			dfs(dep+1,cnt,x,y);
		} else 
		{
			dfs(dep+1,cnt+1,x+f[dep][1],y+f[dep][2]);
		}
	}
}

int main()
{
	freopen("body.in","r",stdin);
	//freopen("body.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i ++)
		scanf("%d",&f[i][1]);
	for (int i=1;i<=n;i ++)
		scanf("%d",&f[i][2]);
	ans = 0.0;
	dfs(1,0,0,0);
	printf("%.3lf\n",ans);
	return 0;
}

