#include <cstdio>

using namespace std;

int map[N][N],cnt[2*N];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int rem=m;
	for (int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j ++)
			scanf("%d",&map[i][j]);
		map[i][0] = k;
	}
	for (int i=1;i<=n;i ++)
	{
		
	}
}
