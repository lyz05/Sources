#include<cstdio>

int n,m,val[60][60],res[60][60][60][60];

void MAX(int &i,int j){if (i<j) i=j;}

int main(){
	freopen("1493.in","r",stdin);

	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) scanf("%d",&val[i][j]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			for (int x=1; x<=n; x++)
				if ( i+j-x>0 && i<x ) {
				int y=i+j-x;
				MAX(res[i][j][x][y],res[i-1][j][x-1][y]);
				MAX(res[i][j][x][y],res[i-1][j][x][y-1]);
				MAX(res[i][j][x][y],res[i][j-1][x-1][y]);
				MAX(res[i][j][x][y],res[i][j-1][x][y-1]);
				res[i][j][x][y] += val[i][j] + val[x][y];
			}
	printf("%d",res[n-1][m][n][m-1]);
}
