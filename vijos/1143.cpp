#include <cstdio>

using namespace std;

const int N=20+2;
int n;
int m[N][N],dp[2*N][N][N][N];

int max(int t1,int t2,int t3,int t4,int t5,int t6,int t7,int t8)
{
	int rec=0;
	rec=t1>t2?t1:t2;
	rec=t3>rec?t3:rec;
	rec=t4>rec?t4:rec;
	rec=t5>rec?t5:rec;
	rec=t6>rec?t6:rec;
	rec=t7>rec?t7:rec;
	rec=t8>rec?t8:rec;
	return rec;
}

int main()
{
	freopen("1143.in","r",stdin);	

	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&m[i][j]);
	
	for (int i=1;i<=2*n-2;i++)
		for (int i1=1;i1<=i+1;i1++)
		for (int i2=1;i2<=i+1;i2++)
		for (int i3=1;i3<=i+1;i3++)
		if (((i1!=i2) || (i2!=i3) || (i1!=i3)) ||
		    ((i1==1) && (i2==1) && (i3==1)) ||
		    ((i1==n) && (i2==n) && (i3==n)) )
		{
			dp[i][i1][i2][i3]=max(
					dp[i-1][i1][i2][i3],
					dp[i-1][i1][i2][i3-1],
					dp[i-1][i1][i2-1][i3],
					dp[i-1][i1][i2-1][i3-1],
					dp[i-1][i1-1][i2][i3],
					dp[i-1][i1-1][i2][i3-1],
					dp[i-1][i1-1][i2-1][i3],
					dp[i-1][i1-1][i2-1][i3-1]
					);
			dp[i][i1][i2][i3]+=m[i1][i-i1+2]+
				m[i2][i-i2+2]+
				m[i3][i-i3+2];
			if (i1==i2) dp[i][i1][i2][i3]-=m[i1][i-i1+2];
			if (i1==i3) dp[i][i1][i2][i3]-=m[i1][i-i1+2];
			if (i2==i3) dp[i][i1][i2][i3]-=m[i2][i-i2+2];
		}
	int ans=dp[2*n-2][n][n][n]+m[n][n]+m[1][1];
	printf("%d\n",ans);
}
