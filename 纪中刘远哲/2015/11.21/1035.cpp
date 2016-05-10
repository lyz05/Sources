#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 55,T = 2505;
int n,m,t;
char a[N][N];
int dp[N][T],sum[N][N],DP[N][T];

int main()
{
	freopen("1035.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d%d",&n,&m,&t);
	for (int i=1;i<=n;i ++) scanf("%s",a[i] + 1);
	
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=m;j ++)
		{
			int num = 0;
			for (int k=j;k<=m;k ++)
			{
				if (a[i][k]=='1') num ++;
				sum[j][k] = max(num,k-j+1-num);
			}
		}
		memset(DP,0,sizeof DP);
		for (int l=1;l<=m;l ++)
		for (int j=1;j<=t;j ++)
		for (int k=0;k<l;k ++)
			DP[l][j] = max(DP[l][j],DP[k][j-1]+sum[k+1][l]);
		for (int j=0;j<=t;j ++)
		for (int k=0;k<=j;k ++)
			dp[i][j] = max(dp[i][j],dp[i-1][k]+DP[m][j-k]);
	}
	printf("%d\n",dp[n][t]);
	return 0;
}

/*
dp[i][j]=max( dp[ i - 1 ][ k ] + w[ i ][ j - k ] )  ( 0 <= k <= j ) 表示前 i 行用了 j 次粉刷的机会能正确粉刷的格子数 , 状态的转移很显然 , w[ i ][ j ] 表示 第 i 行使用 j 次粉刷机会能正确粉刷的格子数.

 接下来考虑 w , 对于每一行 : DP[ i ][ j ] = max( DP[ k ][ j - 1 ] + sum( k + 1 , i ) ) ( 0 <= k < i ) sum( l , r ) 表示从区间[ l , r ] 的颜色相同的格子的个数的较大值( 因为两种颜色 ) , 那么 w[ i ][ j ] = 对第 i 行做的 DP[ m ][ j ] .
 */
