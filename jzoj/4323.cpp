#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 50;
int n,x,y;
int a[N][N];

int main()
{
	//freopen("magic.in","r",stdin);
	//freopen("magic.out","w",stdout);

	scanf("%d",&n);
	x = 1,y = (n+1)/2;
	a[x][y] = 1;
	for (int i=2;i<=n*n;i ++)
	{
		if (x==1 && y!=n) x = n,y = y + 1;
		else if (y==n && x!=1) y = 1,x = x - 1;
		else if (x==1 && y==n) x = x + 1;
		else if (x!=1 && y!=n) 
		{
			if (a[x-1][y+1]==0) x = x-1,y = y+1;
			else x = x+1;
		}
		a[x][y] = i;
	}
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=n;j ++)
			printf("%d ",a[i][j]);
		printf("\n");
	}

	return 0;
}
