#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, -1, 0, 1};

const int N = 55;
int F[N][N], H[N][N], G[N][N];
int n,m;
char map[N][N];


void work(int x,int y,int fx)
{
	if (!(x>=0 && y>=0 && x<n && y<m) || map[x][y] == '#')
	{
		F[x+1][y+1] = H[x+1][y+1] = 0;
		G[x+1][y+1] = 100000000;
		return;
	}
	F[x+1][y+1] = G[x+1][y+1] = 1;
	H[x+1][y+1] = 0;
	//F[x],G[x]所属子树已经炸完,G[x]中x放炸弹,H[x]中所属父亲链未炸完,其他炸完
	int ff[3], gg[3], hh[3];
 
	for (int i = 0; i < 3; ++ i)
	{
		int dir = (i + fx + 1) % 4;
		int xx = x + dirx[dir];
		int yy = y + diry[dir];
		work(xx, yy, (2 + dir) % 4);
		ff[i] = F[xx+1][yy+1];	
		hh[i] = H[xx+1][yy+1];
		gg[i] = G[xx+1][yy+1];
	}

	int hor = min(ff[0] + ff[2], min(hh[0] + gg[2], hh[2] + gg[0]));

	F[x+1][y+1] = min(min(hh[0] + gg[2] + ff[1], 1 + hh[0] + hh[1] + hh[2]), min(hh[2] + gg[0] + ff[1], ff[0] + ff[2] + gg[1]));
	G[x+1][y+1] = min(1 + hh[0] + hh[1] + hh[2], hor + gg[1]);
	H[x+1][y+1] = hor + hh[1];
}

int main()
{
	freopen("3252.in","r",stdin);
	//freopen("3252.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i ++)
	{
		scanf("%s",map[i]);
	}
	for (int i=0;i<n;i ++)
		for (int j=0;j<m;j ++)
		{
			if (map[i][j]=='.')
			{
				work(i,j,1);
				printf("%d",F[i+1][j+1]);
				return 0;
			}
		}

	return 0;
}
