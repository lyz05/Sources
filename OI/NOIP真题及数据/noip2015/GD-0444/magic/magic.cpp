#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 45;
int n,mid,x,y;
int a[N][N];

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	
	scanf("%d",&n);
	mid = (n+1)/2;
	a[1][mid] = 1;
	x = 1;y = mid;
	for (int i=2;i<=n*n;i ++)
	{
		if (x==1 && y!=n) 
		{
			x = n;y = y + 1;
		} else
		if (y==n && x!=1) 
		{
			y = 1, x = x - 1;
		} else
		if (x==1 && y==n)
		{
			x = x+1;
		} else
		if (x!=1 && y!=n) 
		{
			if (a[x-1][y+1]==0) 
			{
				x = x-1, y = y+1;
			} else 
			{
				x = x+1;
			}
		}
		a[x][y] = i;
	}
	//printf("%d\n",n);
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=n-1;j ++)
			printf("%d ",a[i][j]);
		printf("%d",a[i][n]);
		printf("\n");
	}
	return 0;
}

