#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const long long INF = 1042521604759584125;
const int N = 200+10;
LL map[N][N][N];
int pos[N];

struct node
{
	int num,id;
	bool operator < (node a) const
	{
		return num < a.num;
	}
}cos[N];

int main()
{
	//freopen("1061.in","r",stdin);
	
	int T;
	scanf("%d",&T);
	while (T --)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i = 0 ; i < n ; i ++)
		{
			scanf("%d",&cos[i].num);
			cos[i].id = i;
		}
		sort(cos,cos + n);
		for (int i = 0 ; i < n ; i ++)\
		{
			pos[cos[i].id] = i+1;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				map[i][j][0]=INF;
		for (int i = 1 ; i <= m ; i ++)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			map[pos[x]][pos[y]][0] = z;
			map[pos[y]][pos[x]][0] = z;
		}
		for (int k = 1;k <= n; k ++)
		{
			for (int i = 1 ; i <= n ; i ++)
			for (int j = 1 ; j <= n ; j ++)
				map[i][j][k] = map[i][j][k - 1];
			for (int i = 1 ; i <= n ; i ++)
			for (int j = 1 ; j <= n ; j ++)
				map[i][j][k] = min(map[i][j][k],map[i][k][k-1]+map[k][j][k-1]);
			
		}
		int Q;
		scanf("%d",&Q);
		while (Q --)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			LL ans = map[pos[x]][pos[y]][0];
			for (int i = n-1 ; i >= 0; i --)
			{
				if (cos[i].num <= z) {
					ans = map[pos[x]][pos[y]][i+1];
					break;
				}
			}
			if (ans == INF) puts("-1"); else printf("%lld\n",ans);
		}
		printf("\n");
	}
			
	return 0;
}

