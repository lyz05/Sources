#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105,mo = 9397;
int n,m;
int f[N][N];

bool judge(int i,int k)
{
	return (k==i-k+1||min(i-1,n-i+1)==min(i-k+1-1,n+1-i+k-1)||min(i-1,n-i+1)==min(k-1,n-k+1));

}

int main()
{
	freopen("1504.in","r",stdin);
	//freopen("1504.out","w",stdout);

	scanf("%d%d",&n,&m);
	f[2][0] = 1;f[3][1] = 1;
	for (int i=4;i<=n;i ++)
	for (int j=0;j<=m;j ++)	//枚举个数
	for (int k=2;k<i;k ++)	//枚举顶点
	{
		int tmp = judge(i,k);
		for (int l=0;l<=j-tmp;l ++)
		(f[i][j] += f[k][l]*f[i-k+1][j-l-tmp])%=mo;
		
	}
	printf("%d\n",f[n][m]);

	return 0;
}
