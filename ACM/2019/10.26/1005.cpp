#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;

const int N = 200,dir[][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int n,m,ans;
char map[N][N];
int sx,sy,ox,oy,T,vis[N][N];
bool flag1,flag2,f1,f2;

bool judge(int x,int y)
{
	return (map[x][y]!='#' && x>=1 && y>=1 && x<=n && y<=m);
}
//
/*  */
void dfs(int x,int y)
{
	if (flag2) return;
	for (int i=0;i<4;i ++) 
	{
		int tx = x+dir[i][0],ty = y+dir[i][1];
		if (judge(tx,ty) && !vis[tx][ty])
		{
			vis[tx][ty] = 1;
			if (tx==ox && ty==oy) flag1 = 1;
			if (tx==sx && ty==sy) flag2 = 1;
			if (flag1 && flag2) f2 = 1;
			if (flag1) f1 = 1;
				dfs(tx,ty);
			if (tx==ox && ty==oy) flag1 = 0;
			if (tx==sx && ty==sy) flag2 = 0;
			vis[tx][ty] = 0;
		}
	}
}

int main()
{
	freopen("1005.in","r",stdin);
	freopen("1005.out","w",stdout);
	cin >> T;
	while (T --)
	{
		f1 = f2 = 0;
		flag1 = flag2 = 0;
		cin >> n >> m;
		for (int i=1;i<=n;i ++)
			for (int j=1;j<=m;j ++)
			{
				cin >> map[i][j];
				if (map[i][j]=='S') sx = i, sy = j;
				if (map[i][j]=='O') ox = i, oy = j;
			}
		dfs(sx,sy);
		if (f1 && f2) cout << "GoodEnd" << endl;
		else if (f1) cout << "NormalEnd" << endl;
		else cout << "BadEnd" << endl;
	}
	return 0;
}

//5
//1 2 4

//13
//1 2 4 8 
