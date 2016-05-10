#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 3000+5;
struct node
{int x,y,id;} a[N],b[N],c[N];
int p[N];
int ans[N][2],tot,n;

void dfs(int dep,int x,int y,int cnt)
{
	if (dep>n)
	{
		if (x==1e9+7 || y==1e9+7) return;
		if (ans[cnt][0]*ans[cnt][1]<x*y)
		{
			ans[cnt][0] = x;
			ans[cnt][1] = y;
		}
		return;
	}
	for (int i=0;i<=1;i ++)
	{
		if (i % 2==0)
			dfs(dep+1,min(x,a[dep].x),min(y,a[dep].y),cnt+1);
		else	dfs(dep+1,x,y,cnt);
	}
}

int main()
{
	//freopen("family.in","r",stdin);
	//freopen("family.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
	{
		a[i].id = i;
		scanf("%d%d",&a[i].x,&a[i].y);
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	dfs(1,1e9+7,1e9+7,0);
	for (int i=1;i<=n;i ++) printf("%d %d\n",ans[i][0],ans[i][1]);	
	return 0;
}


