#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N =30+2,M = 6,dir[6][3]={{0,0,-1},{0,0,1},{0,-1,0},{0,1,0},{-1,0,0},{1,0,0}};
char map[N][N][N];
bool vis[N][N][N];
int L,R,C;

struct point
{
	int x,y,z,step;
}S,E;

bool check(point now)
{
	int x=now.x,y=now.y,z=now.z;
	return (x>=0 && x<R && y>=0 && y<C && z>=0 && z<L && (map[x][y][z]=='.' || map[x][y][z]=='E'));
}

bool judge(point now)
{
	if (now.x==E.x && now.y==E.y && now.z==E.z)
	{
		E.step = now.step;
		return 1;
	}
	return 0;
}

bool bfs()
{
	queue<point> q;
	q.push(S);
	vis[S.x][S.y][S.z] = 1;
	while (!q.empty())
	{
		point now = q.front();
		q.pop();
		if (judge(now))
		{
			return 1;
		}
		for (int i=0;i<M;i ++)
		{
			point next;
			next.x = now.x + dir[i][0];next.y = now.y + dir[i][1];next.z = now.z + dir[i][2];
			if (check(next) && !vis[next.x][next.y][next.z])
			{
				next.step = now.step + 1;
				vis[next.x][next.y][next.z] = 1;
				q.push(next);
			}
		}
	}
	return 0;
}

int main()
{
	freopen("B.in","r",stdin);
	
	while (1)
	{
		memset(vis,0,sizeof vis);
		scanf("%d%d%d\n",&L,&R,&C);
		if (L==0 && R==0 && C==0) break;
		for (int k=0;k<L;k ++){
			for (int i=0;i<R;i ++)
			{
				for (int j=0;j<C;j ++){
					scanf("%c",&map[i][j][k]);
					if (map[i][j][k]=='S') S.x=i,S.y=j,S.z=k,S.step=0;
					if (map[i][j][k]=='E') E.x=i,E.y=j,E.z=k,E.step=0;
				}
				scanf("\n");
			}
			scanf("\n");
		}
		if (bfs()) 
			printf("Escaped in %d minute(s).\n", E.step);
		else 
			printf("Trapped!\n");
	}
}
