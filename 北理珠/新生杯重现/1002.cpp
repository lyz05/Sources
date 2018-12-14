#include<cstdio>
#include<climits>
#include<algorithm> 
using namespace std;

const int N = 105;
int a[N][N],arr[N][N];
int n;

int main()
{
	freopen("1002.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i ++)
			for (int j=1;j<=n;j ++)
				scanf("%d",&a[i][j]);
		for (int i=0;i<=n;i++) arr[0][i] = arr[i][0] = 1e9+7;
		arr[0][1] = arr[1][0] = 0;
		for (int i=1;i<=n;i ++)
		{
			for (int j=1;j<=n;j ++)
			{
				arr[i][j] = min(arr[i-1][j],arr[i][j-1])+a[i][j];
				//printf("%d ",arr[i][j]);
			}
			//printf("\n");
		}
				
		printf("%d",arr[n][n]);
		if (T!=0) printf("\n\n"); else printf("\n");
	}
	return 0;
}

