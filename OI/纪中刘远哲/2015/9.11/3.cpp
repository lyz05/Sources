#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 50+2 , mo = 1000000007 , kind = 5;
const int dir[kind][2] = {{1,2},{2,1},{3,0},{2,-1},{1,-2}};
int map[3][N][N],f[N][N];
int n,m,ans;
bool flag;

void init(int map[N][N])
{
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
		{
			scanf("%d",&map[i][j]);
			if (map[i][j] == 1) flag = 0;
		}	
}

int calc(int map[N][N])
{
	memset(f,0,sizeof f);
	for (int i=1;i<=m;i ++) 
		if (map[1][i]) f[1][i] = 1;
	for (int x=1;x<=n;x ++)
		for (int y=1;y<=m;y ++)
		{
			if (map[x][y] == 0) continue;
			for (int k=0;k<kind;k ++)
			{
				int tx = x + dir[k][0],ty = y + dir[k][1];
				if (tx<1 || ty<1 || tx>n || ty>m) continue;
				if (!map[tx][ty]) continue;
				f[tx][ty] += f[x][y];
				f[tx][ty] %= mo;
			}
		}
	int sum = 0;
	for (int i=1;i<=m;i ++) sum = (sum + f[n][i]) % mo;
	return sum;
}

int dfs(int x,int y)
{
	int ret = 0;
	if (x == n)
	{
		map[0][x][y] --;
		ret = calc(map[0]);
		map[0][x][y] ++;
		return ret;
	}
	for (int k=0;k<kind;k ++)
	{
		int tx = x + dir[k][0],ty = y + dir[k][1];
		if (tx<1 || ty<1 || tx>n || ty>m) continue;
		if (!map[0][tx][ty]) continue;
		map[0][x][y] --;
		ret = (ret + dfs(tx,ty)) % mo;
		map[0][x][y] ++;
	}
	return ret;
}

int main()
{
	freopen("pond.in","r",stdin);
	freopen("pond.out","w",stdout);

	flag = 1;	
	scanf("%d%d",&n,&m);
	init(map[0]);
	if (flag)		//2
	{
		int sum = calc(map[0]);
		ans = ((long long)sum*sum) % mo;
	} else 
	{
		//memcpy(map[1],map[0],sizeof map[0]);
		int sum = 0;
		for (int i=1;i<=m;i ++)
			if (map[0][1][i]) 
				sum = (sum + dfs(1,i)) % mo;
		ans = sum;
	}
	printf("%d\n",ans);
	return 0;
}
