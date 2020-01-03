#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

const int N = 5,dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int map[N+2][N+2];
int cnt=-1,ans=INT_MAX;

struct pair
{
	int x,y;
} now[N*N],Ans[N*N];


bool judge(int x,int y)
{return x>=0 && x<N && y>=0 && y<N;}


void dfs(int x,int y)
{
	if (map[x][y]==1) return;
	map[x][y]=1;
	now[++ cnt].x = x,now[cnt].y=y;
	if (x==N-1 && y==N-1)
	{
		if (cnt<ans) 
		{
			ans = cnt;
			memcpy(Ans,now,sizeof(now));
		}
		map[x][y] = 0;
		cnt --;
		return;
	}
	for (int i=0;i<4;i ++)
	{
		int tx = x+dir[i][0],ty = y+dir[i][1];
		if (judge(tx,ty))
			dfs(tx,ty);
	}
	map[x][y] = 0;
	cnt --;
}

int main()
{
	freopen("F.in","r",stdin);
	for (int i=0;i<N;i ++)
		for (int j=0;j<N;j ++)
			scanf("%d",&map[i][j]);
	dfs(0,0);
	//printf("%d\n",ans);
	if (ans<=N*N)
		for (int i=0;i<=ans;i ++) printf("(%d,%d)\n",Ans[i].x,Ans[i].y);
	return 0;
}
