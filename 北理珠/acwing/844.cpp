#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100+5;
const int dir[4][2]={0,1,0,-1,1,0,-1,0};
int n,m,map[N][N],ans,len;
bool p[N][N];
queue<int> q;

bool judge(int x,int y)
{
	if (x<1 || y<1 || x>n || y>m) return 0;
	return !map[x][y];
} 

void bfs()
{
	q.push(1,1);
}

int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
			cin >> map[i][j];
	bfs();
	cout << ans << endl;
	return 0;
} 
