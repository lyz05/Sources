#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 105, D = 105,dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,d;
int map[N][N],vis[N][N][D];

struct node
{
	int x,y,step,remain;
	node(int a,int b,int c,int d) 
	{x = a,y = b,step = c,remain = d;}
};

bool judge(int x,int y)
{
	return x>0 && y>0 && x<=n && y<=m;
}

void bfs()
{
	memset(vis,0,sizeof vis);
	queue <node> buffer;
	buffer.push(node(1,1,0,d));
	vis[1][1][d] = 1;
	while (!buffer.empty())
	{
		node tmp = buffer.front();
		buffer.pop();
		if (tmp.x==n && tmp.y==m)
		{
			printf("%d\n",tmp.step);
			return;
		}
		int tx,ty,s = tmp.step+1,r = tmp.remain;
		for (int i=0;i<4;i ++)
		{
			tx = tmp.x + dir[i][0];
			ty = tmp.y + dir[i][1];
			if (judge(tx,ty) && !vis[tx][ty][r] && map[tx][ty])
			{
				buffer.push(node(tx,ty,s,r));
				vis[tx][ty][r] = 1;
			}
			for (int j=2;j<=r;j ++)
			{
				tx += dir[i][0],ty += dir[i][1];
				if (judge(tx,ty) && !vis[tx][ty][r-j] && map[tx][ty])
				{
					buffer.push(node(tx,ty,s,r-j));
					vis[tx][ty][r-j] = 1;
				}
			}
		}
	}
	printf("impossible\n");
}

int main()
{
	//freopen("1028.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d%d\n",&n,&m,&d);
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=m;j ++)
		{	
			char ch;
			scanf("%c",&ch);
			if (ch=='P') map[i][j] = 1;
		}
		scanf("\n");
	}
	bfs();
	return 0;
}

