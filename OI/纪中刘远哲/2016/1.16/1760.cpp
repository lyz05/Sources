#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 20;
queue <int> Q;
int n,K,now;
int map[N][N],f[1<<N],vis[1<<N];

int main()
{
	freopen("data.in","r",stdin);
	//freopen("1760.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
		scanf("%d",&map[i][j]);
	K = (1<<n)-1;
	memset(f,124,sizeof f);

	Q.push(0);
	f[0] = 0;
	vis[0] = 1;
	while ((now = Q.front()) != K && !Q.empty())
	{
		Q.pop();
		for (int i=0;i<n;i ++)
		if ((now&(1<<i))==0) 
		for (int j=i+1;j<n;j ++)
		if ((now&(1<<i))==0)
		{
			int y = now | (1<<i) | (1<<j);
			f[y] = min(f[y],f[now] + map[i+1][j+1]);
			if (!vis[y])
			{
				vis[y] = 1;
				Q.push(y);
			}
		}
	}
	printf("%d\n",f[K]);
	return 0;
}
