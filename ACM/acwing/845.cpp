#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int N = 4;
const int dir[4][2]={0,1,0,-1,1,0,-1,0};
int ans,len;

struct Node
{
	char map[N][N];
	int x,y;
};
map<Node,int> Map;
Node S,T;
queue<Node> q;

bool judge(int x,int y)
{
	if (x<1 || y<1 || x>3 || y>3) return 0;
	return 1;
} 

void swap(Node &now,int x,int y,int tx,int ty)
{
	char t = now.map[x][y];
	now.map[x][y] = now.map[tx][ty];
	now.map[tx][ty] = t;
}

int bfs()
{
	q.push(S);
	while (!q.empty())
	{
		Node now = q.front();q.pop();
		int len = Map[now];
		if (Map[T]>0) return Map[T];
		for (int i=0;i<4;i ++)
		{
			int tx = now.x+dir[i][0],ty = now.y+dir[i][1];
			if (judge(tx,ty) && Map[now]==0)
			{
				swap(now,now.x,now.y,tx,ty);
				Map[now] = len+1;
				q.push(now);
			}
		}
	}
}

int main()
{
	for (int i=1;i<=3;i ++)
		for (int j=1;j<=3;j ++)
		{
			T.map[i][j] = ((i-1)*3)+j;
			cin >> S.map[i][j];
			if (S.map[i][j]=='X') S.x = i,S.y = j;
		}
	T.map[3][3] = 'X';
	T.x = 3,T.y = 3; 
	cout << bfs() << endl;
	
	return 0;
} 
