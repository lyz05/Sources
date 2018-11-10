#include<cstdio>
#include<iostream>
using namespace std;

const int N = 15;
const char name[3][3] = {"\0","白","黑"};	//棋子名字
int map[N+1][N+1];							//棋盘

void print_chess_board();					//打印棋盘
void init();								//游戏初始化
void work();								//游戏主程序
int is_win(int x,int y,int color);			//判断颜色color的落子于(x,y)是否赢棋
bool check(int x);							//检测棋子坐标越界

int main()
{
	init();
	work();
	return 0;
}

bool check(int x)
{
	return ((x<0) || (x>=N));
}

void print_chess_board()						//打印棋盘
{
	for (int j=0;j<=N;j ++) printf("%-3d",j);
	puts("");
	for (int i=1;i<=N;i ++)
	{
		printf("%-3d",i);
		for (int j=1;j<=N;j ++)
		{
			printf("%-3d",map[i][j]);
		}
		puts("");
	}
}

int is_win(int x,int y,int color)
{
	int count = 0;
	int i,j;
	int size = 15;
	//扫描行
	for (i=(x-4>0?x-4:0); (i<=x+4)&&(i<size); i++) 
	{
		if (color == (map[i][y]))
		{
			count++;
			if (count >= 5)
			{
				return true;
			}
		}
		else
		{
			count = 0;
		}
	}
	//扫描列
	count = 0;
	for (j=(y-4>0?y-4:0); (j<=y+4)&&(j<size); j++) 
	{
		if (color == (map[x][j]))
		{
			count++;
			if (count >= 5)
			{
				return true;
			}
		}
		else
		{
			count = 0;
		}
	}
	//扫描正斜线(\)
	count = 0;
	for (i=x-4,j=y-4;(i<=x+4)&&(i<size)&&(j<=y+4)&&(j<size); i++,j++) 
	{
		if (check(i) || check(j)) continue;
		if (color == (map[i][j]))
		{
			count++;
			if (count >= 5)
			{
				return true;
			}
		}
		else
		{
			count = 0;
		}
	}
	//扫描反斜线(/)
	count = 0;
	for (i=x-4,j=y+4;(i<=x+4)&&(i<size)&&(j>=y-4)&&(j>=0); i++,j--) 
	{
		if (check(i) || check(j)) continue;
		if (color == (map[i][j]))
		{
			count++;
			if (count >= 5)
			{
				return true;
			}
		}
		else
		{
			count = 0;
		}
	}
	return false;
}

void init()
{
	printf("欢迎使用五子棋程序\n");
	printf("游戏中0代表无棋，1代表黑棋，2代表白棋\n");
	printf("********************\n");
}

int judge()								
{
	int board[3*N][2];					//记录边界坐标
	int sum[3][N+1];
	//边界初始化
	for (int i=1;i<=N;i ++) board[i][0] = N-i+1,board[i][1] = 1;
	for (int i=N+1;i<=2*N-1;i ++) board[i][0] = 1,board[i][1] = i-N+1;
	for (int i=2*N;i<=3*N-2;i ++) board[i][0] = i-2*N+2,board[i][1] = N;
	//扫描行
	for (int i=1;i<=N;i ++)
	{
		memset(sum,0,sizeof sum);
		for (int j=1;j<=N;j ++)
		{
			int now = map[i][j];		//当前棋子的颜色
			sum[now][j] += sum[now][j-1]+1;
			if (now!=0 && sum[now][j]>=5) return now;
		}
	}
	//扫描列
	for (int j=1;j<=N;j ++)
	{
		memset(sum,0,sizeof sum);
		for (int i=1;i<=N;i ++)
		{
			int now = map[i][j];		//当前棋子的颜色
			sum[now][i] += sum[now][i-1]+1;
			if (now!=0 && sum[now][i]>=5) return now;
		}
	}
	/*扫描“\”*/
	for (int i=1;i<=2*N-1;i ++)
	{
		memset(sum,0,sizeof sum);
		for (int x=board[i][0],y=board[i][1],cnt = 1;
			x>0 && y>0 && x<=N && y<=N;x++,y++,cnt ++)
		{
			int now = map[x][y];
			sum[now][cnt] += sum[now][cnt-1]+1;
			if (now!=0 && sum[now][cnt]>=5) return now;
		}
	}
	/*扫描“/”*/
	for (int i=N;i<=3*N-2;i++)
	{
		memset(sum,0,sizeof sum);
		for (int x=board[i][0],y=board[i][1],cnt = 1;
			x>0 && y>0 && x<=N && y<=N;x++,y--,cnt ++)
		{
			int now = map[x][y];
			sum[now][cnt] += sum[now][cnt-1]+1;
			if (now!=0 && sum[now][cnt]>=5) return now;
		}
	}
	return 0;
}

void work()
{
	printf("请按任意键开始游戏！\n");
	system("pause");
	memset(map,0,sizeof map);
	for (int tot=1;;tot++)
	{
		int now = (tot-1)%2+1;
		system("cls");
		init();
		int x,y,flag;
		print_chess_board();
		if (flag=judge()) {
			printf("游戏结束！%s子获胜！\n",name[flag]);
			return;
		}
		printf("当前为第%d轮,现在轮到%s子下棋",tot,name[now]);
		printf("请输入你要下棋的坐标，用空格隔开\n");
		scanf("%d%d",&x,&y);
		map[x][y] = now;
		//for (int k=1;k<=10;k ++) printf("\b");
	}
}



