#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int n,m,a[205][205];

int main()
{
	freopen("1001.in","r",stdin);

	memset(a,50,sizeof a);
	scanf("%d %d",&n,&m);
	if (n==1) printf("0"); else
       	{
		for (int i=1;i<=m;i ++)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			a[x][y] = min(a[x][y],z);
			a[y][x] = min(a[y][x],z);
		}
		for (int k=1;k<=n;k ++)
		       for (int i=1;i<=n;i ++)
			       for (int j=1;j<=n;j ++)
				       if (i!=j && i!=k && j!=k && a[i][k]!=a[0][0] && a[k][j]!=a[0][0])
					       if (a[i][j]>a[i][k]+a[k][j])
						       a[i][j]=a[i][k]+a[k][j];
		if (a[1][n]!=a[0][0]) printf("%d\n",a[1][n]); 
			else printf("-1");
	}
}
