#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000+5;
int n,m,ans;
int a[N][N];

bool judge(int len)
{
	for (int i=1;i<=n-len+1;i ++)
	for (int j=1;j<=m-len+1;j ++)
	{
	bool flag = 1;
	for (int p=0;p<len && flag;p ++)
	for (int q=0;q<len && flag;q ++)
	{
		for (int x=p+1;x<len && flag;x ++)
		for (int y=q+1;y<len && flag;y ++)
			if ((a[i+p][j+q]+a[i+x][j+y]) > (a[i+p][j+y]+a[i+x][j+q]))
			{
				flag = 0;
				break;
			}
	}
	if (flag) return 1;
	}
	return 0;
}

int main()
{
	freopen("4260.in","r",stdin);
	//freopen("mission.out","w",stdout);
	
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i ++)
		for (int j=1;j<=n;j ++)
			scanf("%d",&a[i][j]);
	
	int l=0,r=m*n;
	while (l<=r)
	{
		int mid = (l+r)>>1;
		if (judge(mid))
		{
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}


	return 0;
}
