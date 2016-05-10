#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 200+10;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int f[2][N][N],q[N],v[N];
char map[N][N];
int x1,x2;

void solve(int x,int y,int w,int L , int c)
{
	int l=0,r=-1,tmp;
	for (int i = 1 ; i <= w ; i ++)
	{
		if (map[x][y-1] == '.')
		{
			tmp = f[x1][x][y] + w - i;
			while (l<=r && tmp>v[r]) r--;
			v[++r] = tmp;
			q[r] = i;
			while (i-q[l]>L) l++;
			f[x2][x][y] = v[l] - w + i;
		} else l = r + 1,f[x2][x][y] = - 2e9;
		x += dx[c];
		y += dy[c];
	}
}

int main()
{
	freopen("2412.in","r",stdin);

	int n,m,x,y,k;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);
	for (int i=1 ; i <= n ; i ++)
		scanf("%s",map[i]);
	for (int i=1 ; i<=n ; i++)
	for (int j = 1 ; j <= m ; j ++)
		f[0][i][j] = -2e9;
	f[0][x][y] = 0;
	
	x1=1;x2=0;
	while (k --)
	{
		int a,b,c,i,j;
		x1 = 1 - x1;x2 = 1 - x2;
		scanf("%d%d%d",&a,&b,&c);
		if (c==1) for (j=1;j<=m;j++) solve(n,j,n,b-a+1,c-1);
		if (c==2) for (j=1;j<=m;j++) solve(1,j,n,b-a+1,c-1);
		if (c==3) for (i=1;i<=n;i++) solve(i,m,m,b-a+1,c-1);
		if (c==4) for (i=1;i<=n;i++) solve(i,1,m,b-a+1,c-1);
	}

	int ans=0;
	for (int i=1; i <=n ; i ++)
		for (int j = 1 ; j <=m ; j++)
			ans = max (ans , f[x2][i][j]);
	printf("%d\n",ans);

	return 0;
}
