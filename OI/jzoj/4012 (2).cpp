#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int mo = 1000000007;
const int N = 1005;
int map[N][N];
int n , m , k;
int zs[N][N] , yx[N][N] , ci[N] , whe[N];

void Init()
{
	scanf("%d%d%d",&n,&m,&k);
	fo(i,1,n) fo(j,1,m) scanf("%d",&map[i][j]) , ci[map[i][j]]++;
	fd(i,n,1) fd(j,m,1) yx[i][j] = yx[i+1][j] | yx[i][j+1] | (1<<map[i][j]);
}

int dfs(int x,int y)
{
	if (x > n) return 1;
	zs[x][y] = zs[x-1][y] | zs[x][y-1];
	int ret = 0;
	if (map[x][y])
	{
		int i = map[x][y];
		if (!(((zs[x][y] & (1<<i)) == 0) && (((yx[x+1][y]|yx[x][y+1]) & (1<<i)) == 0) && whe[i] > y)) return 0;
		int o = whe[i];
		whe[i] = y;
		zs[x][y] ^= (1<<i);
		if (y == m) ret = dfs(x+1,1);else ret = dfs(x,y+1);
		zs[x][y] ^= (1<<i);
		whe[i] = o;
		return ret;
	}
	
	int sum = 0 , d = 0;
	fo(i,1,k) if (!ci[i]) sum++;
	ret = 0;
	bool ok = 1;
	fo(i,1,k)
	if (((zs[x][y] & (1<<i)) == 0) && ((yx[x][y] & (1<<i)) == 0) && whe[i] > y)
	{
		if (!ci[i] && !ok) continue;
		map[x][y] = i;
		int o = whe[i];
		whe[i] = y;
		zs[x][y] ^= (1 << i);
		
		if (!ci[i])
		{
			ci[i] ++;
			ok = 0;
			if (y == m) ret = dfs(x+1,1);else ret = dfs(x,y+1);
			ci[i] --;
		}
		else
		{
			ci[i] ++;
			if (y == m) d += dfs(x+1,1);else d += dfs(x,y+1);
			ci[i] --;
		}
		zs[x][y] ^= (1 << i);
		whe[i] = o;
		map[x][y] = 0;
	}
	return (d + ret*sum) % mo;
}

void Work()
{
	if (n + m - 1 > k)
	{
		puts("0");
		return;
	}
	fo(i,1,k) whe[i] = m + 1;
	printf("%d\n",dfs(1,1));
}

int main()
{
	
	Init();
	Work();
	
	return 0;
}
