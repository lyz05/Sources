#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FOR(i,a,b) for (int i=a;i<=b;i ++)
using namespace std;

const int M = 1005,W = 100005,N = 55,JD = 1000;

int n,m,T,f[N][N][N];
double ans;

int main()
{	freopen("1224.in","r",stdin);
	//freopen(".out","w",stdout);

	memset(f,62,sizeof f);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		f[1][x][y] = min(f[1][x][y],z);
	}
	FOR (l,1,n)
	FOR (k,1,n)
	FOR (i,1,n)
	FOR (j,1,n)
		f[l][i][j] = min(f[l][i][j],f[l-1][i][k]+f[1][k][j]);
	scanf("%d",&T);
	while (T --) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans = 1e6;
		FOR (i,1,n) ans = min(ans,(double)f[i][x][y]/i);
		if (ans<1e6) printf("%.3f\n",ans); else puts("OMG!");
	}

	return 0;
}
