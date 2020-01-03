#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 7 , k = 1 << 20, inf = 1e9+7;
int n,m,o;
int a[N][N],b[N][N],c[21];
int f[k];
bool p[k];

int check(int x,int y)
{
	int t = 0;
	if ((a[x-1][y-1]==a[x-1][y])&&(a[x-1][y]==a[x][y-1])&&(a[x][y-1]==1)) t += b[x-1][y-1];
	if ((a[x-1][y+1]==a[x-1][y])&&(a[x-1][y]==a[x][y+1])&&(a[x][y+1]==1)) t += b[x-1][y];
	if ((a[x+1][y-1]==a[x+1][y])&&(a[x+1][y]==a[x][y-1])&&(a[x][y-1]==1)) t += b[x][y-1];
	if ((a[x+1][y+1]==a[x+1][y])&&(a[x+1][y]==a[x][y+1])&&(a[x][y+1]==1)) t += b[x][y];
	return t;
}

int dfs(int z)
{
	if (z==o-1) return 0;
	if (p[z]) return f[z];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			int t1 = c[(i-1)*m+j-1];
			if ((z & t1)==t1) continue;
			int t = check(i,j);
			a[i][j] = 1;
			if (t)  f[z] = max(f[z],dfs(z+t1)+t);
			else f[z] = max(f[z],(-dfs(z+t1)));
			a[i][j] = 0;
		}
	p[z] = true;
	return f[z];
}

int main()
{
	freopen("4365.in","r",stdin);
	
	scanf("%d%d",&n,&m);
	int t = 1;
	int t1 = 0;
	for(int i=1; i<=n*m+1; i++)
	{
		c[i-1] = t;
		t = t << 1;
	}
	t = 1;
	o = c[n*m];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			scanf("%d",&a[i][j]);
			if (a[i][j]) t1 = t1 + t;
			t = t << 1;
		}
	for(int i=0; i<=o; i++) f[i] = -inf;
	memset(p,0,o+1);
	for(int i=1; i<=n-1; i++)
		for(int j=1; j<=m-1; j++) scanf("%d",&b[i][j]);
	
	t = dfs(t1);
	printf("%d",t);
	
	return 0;
}
