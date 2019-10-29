#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100+5;
const int dir[4][2]={0,1,0,-1,1,0,-1,0};
typedef pair<int,int> PII;
int n,m,map[N][N],d[N][N],ans,len;
bool p[N][N];

queue<PII> q;

bool judge(int x,int y)
{
	if (x<1 || y<1 || x>n || y>m) return 0;
	return !map[x][y];
} 

void bfs()
{
	q.push(PII(1,1));
	d[1][1] = 0;
	while (!q.empty())
	{
		PII now = q.front();q.pop();
		for (int i=0;i<4;i ++)
		{
			int tx = now.first+dir[i][0],ty = now.second+dir[i][1];
			if (judge(tx,ty) && d[tx][ty]==-1)
			{
				d[tx][ty] = d[now.first][now.second]+1;
				q.push(PII(tx,ty));
			}
		}
	}
}

int main()
{
	for (int i=1;i<=3;i ++)
		for (int j=1;j<=3;j ++)
			cin >> map[i][j]; 
	bfs();
	cout << d[n][m] << endl;
	return 0;
} 
