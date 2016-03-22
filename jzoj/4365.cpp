#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 8,M = (1<<20)+5;
int n,m,now;
int f[M],a[N][N],b[N][N],bit[25];
bool flag[M];

int calc(int x,int y)
{
	return (x-1)*m+y-1;
}

int get(int x,int y)
{

	int ret = 0;
	if ((a[x-1][y-1]==a[x-1][y])&&(a[x-1][y]==a[x][y-1])&&(a[x][y-1]==1)) ret += b[x-1][y-1];
	if ((a[x-1][y+1]==a[x-1][y])&&(a[x-1][y]==a[x][y+1])&&(a[x][y+1]==1)) ret += b[x-1][y];
	if ((a[x+1][y-1]==a[x+1][y])&&(a[x+1][y]==a[x][y-1])&&(a[x][y-1]==1)) ret += b[x][y-1];
	if ((a[x+1][y+1]==a[x+1][y])&&(a[x+1][y]==a[x][y+1])&&(a[x][y+1]==1)) ret += b[x][y];
	return ret;
}

int dfs(int x)
{
	if (x==bit[n*m]-1) return 0;
	if (flag[x]) return f[x];
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
		{
			int t = bit[calc(i,j)];
			if (x & t) continue;
			a[i][j] = 1;
			int val = get(i,j);
			if (val) f[x] = max(f[x],dfs(x+t)+val);
			else f[x] = max(f[x],-dfs(x+t));
			a[i][j] = 0;
		}
	flag[x] = 1;
	return f[x];
}

int main()
{
	freopen("4365.in","r",stdin);
	//freopen("4365.out","w",stdout);

	scanf("%d%d",&n,&m);
	bit[0] = 1;
	for (int i=1;i<=n*m;i ++) bit[i] = bit[i-1]<<1;
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=m;j ++)
	{
		scanf("%d",&a[i][j]);
		if (a[i][j]) now += bit[calc(i,j)];
	}
	
	memset(f,225,sizeof f);
	for (int i=1;i<n;i ++)
	for (int j=1;j<m;j ++)
		scanf("%d",&b[i][j]);
	int ans = dfs(now);
	printf("%d\n",ans);
	

	return 0;
}
