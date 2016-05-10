#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 36+5,mo = 998244353;
struct node 
{
	int x,y;
} a[N];
int map[N][N];
int n,ans;

bool cmp1(node x,node y)
{return x.x<y.x;}
bool cmp2(node x,node y)
{return x.y<y.y;}


void dfs(int dep)
{
	int x = a[dep].x, y = a[dep].y;
	if (dep>n)
	{
		ans = (ans + 1) % mo;
		return;
	}
	for (int i=1;i<=4;i ++)
	{
		int tx,ty;
		bool flag = 0;
		if (i==1)
		{
			ty = y;
			for (tx=x+1;tx<=n;tx ++) 
				if (map[tx][ty]!=0) 
				{
					flag = 1;
					break;
				}
			if (flag) continue;
			for (tx=x+1;tx<=n;tx ++) 
				if (map[tx][ty]==0) map[tx][ty] = 1;
			dfs(dep+1);
			for (tx=x+1;tx<=n;tx ++) 
				if (map[tx][ty] == 1) map[tx][ty] = 0;
		}
		if (i==2)
		{
			ty = y;
			for (tx=x-1;tx>=1;tx --) 
				if (map[tx][ty]!=0) 
				{
					flag = 1;
					break;
				}
			if (flag) continue;
			for (tx=x-1;tx>=1;tx --) 
				if (map[tx][ty]==0) map[tx][ty] = 1;
			dfs(dep+1);
			for (tx=x-1;tx>=1;tx --) 
				if (map[tx][ty] == 1) map[tx][ty] = 0;
		}
		if (i==3)
		{
			tx = x;
			for (ty=y+1;ty<=n;ty ++) 
				if (map[tx][ty]!=0) 
				{
					flag = 1;
					break;
				}
			if (flag) continue;
			for (ty=y+1;ty<=n;ty ++) 
				if (map[tx][ty]==0) map[tx][ty] = 1;
			dfs(dep+1);
			for (ty=y+1;ty<=n;ty ++) 
				if (map[tx][ty] == 1) map[tx][ty] = 0;
		}
		if (i==4)
		{
			tx = x;
			for (ty=y-1;ty>=1;ty --) 
				if (map[tx][ty]!=0) 
				{
					flag = 1;
					break;
				}
			if (flag) continue;
			for (ty=y-1;ty>=1;ty --) 
				if (map[tx][ty]==0) map[tx][ty] = 1;
			dfs(dep+1);
			for (ty=y-1;ty>=1;ty --) 
				if (map[tx][ty] == 1) map[tx][ty] = 0;
		}
	}
}

int main()
{
	freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}

	sort(a+1,a+1+n,cmp1);
	int num = 1;
	for (int i=1;i<=n;i ++)
	{
		if (a[i].x!=a[i+1].x && i<n) 
		{
			a[i].x = num;
			num ++;
		} else a[i].x = num;
	}
	sort(a+1,a+1+n,cmp2);
	num = 1;
	for (int i=1;i<=n;i ++)
	{
		if (a[i].y!=a[i+1].y && i<n) 
		{
			a[i].y = num;
			num ++;
		} else a[i].y = num;
	}

	for (int i=1;i<=n;i ++)
		map[a[i].x][a[i].y] = 2;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
