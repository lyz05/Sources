#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 105;
const int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int n,m,Ans;
int map[N][N],ans[N][N];


int dfs(int x,int y)
{
	if (ans[x][y]) return ans[x][y];
	int sum = 0;
	for (int i = 0;i < 4;i ++)
	{
		int tx = x+dir[i][0],ty = y+dir[i][1];
		if (tx<1 || ty<1 || tx>n || ty>m) continue;
		if (map[tx][ty]>=map[x][y]) continue;
		if (!ans[tx][ty]) dfs(tx,ty);
		sum = max(dfs(tx,ty),sum);
	}
	sum ++;
	return ans[x][y] = sum;
}

int main()
{
	freopen("F.in","r",stdin);
	cin >> n >> m;
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
		{
			cin >> map[i][j];
		}
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
		{
			if (!ans[i][j]) dfs(i,j);
			Ans = max(Ans,ans[i][j]);
		}
	cout << Ans << endl;
	return 0;
}
