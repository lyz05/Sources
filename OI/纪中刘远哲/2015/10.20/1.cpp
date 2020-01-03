#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int dir[6][3]={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
const int N = 150000+5;
int n,ans,a[5][N],s[5][N],b[5][5];

void work()
{
	for (int i=0;i<6;i++)
	{
		int tmp = 0;
		for (int j=1;j<=3;j ++)
			tmp += b[dir[i][j-1]][j];
		ans = min(ans,tmp);
	}
}

int main()
{
	//freopen("acm.in","r",stdin);
	//freopen("acm.out","w",stdout);

	scanf("%d",&n);
	for (int j=1;j<=3;j ++)
		for (int i=1;i<=n;i ++) 
			scanf("%d",&a[j][i]), s[j][i]=s[j][i-1]+a[j][i];
	
	ans = 1e9+7;
	for (int i=1;i<=n-2;i ++)
		for (int j=i+1;j<=n-1;j++)
		{
			for (int k=1;k<=3;k ++)
			{
				b[k][1] = s[k][i];
				b[k][2] = s[k][j] - s[k][i];
				b[k][3] = s[k][n] - s[k][j];
			}
			work();
		}
	printf("%d\n",ans);

	return 0;
}

