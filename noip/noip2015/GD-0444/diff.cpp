#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100;
int n,tmp,ans;
int a[N][N];
bool flag;

int main()
{
	//freopen("magic.out","r",stdin);
	//freopen(".out","w",stdout);
	flag = 1;
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
		for (int j=1;j<=n;j ++) 
			scanf("%d",&a[i][j]);

	ans = 0;
	for (int i=1;i<=n;i ++) ans += a[1][i];
	for (int i=1;i<=n;i ++)
	{
		tmp = 0;
		for (int j=1;j<=n;j ++)
		{
			tmp += a[i][j];
		}
		if (tmp!=ans) flag = 0;
	}
	for (int j=1;j<=n;j ++)
	{
		tmp = 0;
		for (int i=1;i<=n;i ++)
		{
			tmp += a[i][j];
		}
		if (tmp!=ans) flag = 0;
	}
	tmp = 0;
	for (int i=1;i<=n;i ++) tmp += a[i][i];
	if (tmp!=ans) flag = 0;
	tmp = 0;
	for (int i=1;i<=n;i ++) tmp += a[i][n-i+1];
	if (tmp!=ans) flag = 0;
	if (flag)
	{
		printf("%d\n",n);
		for (int i=1;i<=n;i ++) 
		{
			for (int j=1;j<=n-1;j ++) 
				printf("%d ",a[i][j]);
			printf("%d",a[i][n]);
			puts("");
		}
	} else	printf("WA!\n");
	return 0;
}

