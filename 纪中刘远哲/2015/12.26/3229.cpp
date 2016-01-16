#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

const int N = 305,M = N;
int n,m,ans,Ans;
int a[N][N];
bool sum[2][M][M][M];

void work1()
{
	memset(sum,0,sizeof sum);
	for (int i=1;i<=n;i ++)
	for (int mid=1;mid<=m;mid ++)
	{
		int l = mid,r = mid;
		while (l>0 &&r<=m && a[i][l]==a[i][r]) 
		{
			sum[0][i][l][r-l+1] = 1;
			l--,r++;
		}
	}
	for (int j=1;j<=m;j ++)
	for (int mid=1;mid<=n;mid ++)
	{
		int l = mid,r = mid;
		while (l>0 &&r<=n && a[l][j]==a[r][j]) 
		{
			sum[1][l][j][r-l+1] = 1;
			l--,r++;
		}
	}
}

void work2()
{
	memset(sum,0,sizeof sum);
	for (int i=1;i<=n;i ++)
	{
		for (int k=1;k<m;k ++)
		{
			int l = k,r = k+1;
			while (l>0 &&r<=m && a[i][l]==a[i][r]) 
			{
				sum[0][i][l][r-l+1] = 1;
				l--,r++;
			}
		}
	}
	for (int j=1;j<=m;j ++)
	{
		for (int k=1;k<n;k ++)
		{
			int l = k,r = k+1;
			while (l>0 &&r<=n && a[l][j]==a[r][j]) 
			{
				sum[1][l][j][r-l+1] = 1;
				l--,r++;
			}
		}
	}
	return;
}

void judge()
{
	for (int ans=min(n,m);ans;ans --)
	{
		for (int i=1;i<=n && i+ans-1<=n;i ++)
		for (int j=1;j<=m && j+ans-1<=m;j ++)
		{
			bool flag =1;
			for (int k=0;k<ans;k ++)
				if(!sum[0][i+k][j][ans] || !sum[1][i][j+k][ans])
				{			
					flag = 0;
					break;
				}
			if (flag) 
				Ans = max(ans,Ans);
		}
	}
}

int main()
{
	freopen("3229.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) 
	for (int j=1;j<=m;j ++) scanf("%d",&a[i][j]);
	
	work1();
	judge();
	work2();
	judge();
	printf("%d\n",Ans);
	return 0;
}
