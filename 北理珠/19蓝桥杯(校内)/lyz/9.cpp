#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000+7,M = 4;
const int dir[M][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int a[N][N],num,n,m,r,c;

bool judge(int x,int y)
{
	if (x>n || y>m || x<1 || y<1) return 0;
	if (a[x][y]) return 0;
	return 1;
}

int main()
{
	//freopen("data.in","r",stdin);
	//freopen(".out","w",stdout);

	cin >> n >> m >> r >> c;
	num = 1;
	
	int x = 1,y = 1,fx = 0;
	for (int i=1;i<=n*m;i ++)
	{
		a[x][y] = num ++;
		for (int i=0;i<=1;i++)
		{
			int tfx = (fx+i)%M;
			int tx = x+dir[tfx][0],ty = y+dir[tfx][1];
			if (judge(tx,ty))
			{
				x = tx;
				y = ty;
				fx = tfx;
				break;
			}
		}
	}
	
	cout << a[r][c];
	/*
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=m;j ++)
			cout  << a[i][j] << " ";
		cout << endl;
	}
	*/ 
	return 0;
}
