#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

const int N = 200+7,INF = 202116108;
int map[N][N],n,m,T;

void floyd()
{
	for (int k=1;k<=n;k ++)
		for (int i=1;i<=n;i ++)
			for (int j=1;j<=n;j ++)
				if (map[i][k]+map[k][j]<map[i][j] && (map[i][k]!=INF && map[k][j]!=INF))
					map[i][j] = map[i][k]+map[k][j];
}

int main()
{
	freopen("854.in","r",stdin);
	memset(map,12,sizeof map);
	cin >> n >> m >> T;
	for (int i=1;i<=n;i ++) map[i][i] = 0;
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		map[x][y] = min(map[x][y],z);
	}
	floyd();
	while (T --)
	{
		int x,y;
		cin >> x >> y;
		if (map[x][y] == INF) cout << "impossible" << endl;
		else cout << map[x][y] << endl;
	}
	return 0;
}
