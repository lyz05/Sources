#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int N = 200+2,M = 4*N;
int n,m,tot;
int a[N],map[N][N];


int main()
{
	freopen("L2-4.in","r",stdin);
	cin >> n >> m;
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		map[x][y] = z;
		map[y][x] = z;
	}
	int T;
	cin >> T;
	int ans = 1e9+7,ok = 0,k = 0;
	for (int i=1;i<=T;i ++)
	{
		bool flag = 1;
		int len,dis = 0;
		cin >> len;
		for (int j=1;j<=len;j ++) 
			cin >> a[j];
		a[0] = 0;
		a[len+1] = 0;
		for (int j=1;j<=len+1;j ++)
		{
			if (map[a[i-1]][a[i]]==0) {
				flag = 0;
				break;
			}
			dis += map[a[i-1]][a[i]];
		}
		if (flag) ok ++;
		if (dis<ans)
		{
			k = i;
			ans = dis;
		}
	}
	printf("%d\n%d %d",ok,k,ans);
	return 0;
}
