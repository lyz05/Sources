#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

const int inf=0x3f3f3f3f;

struct node
{
  int x,y;
};

struct dog
{
  int x,y,now;
};

queue<node>q;

queue<dog>Q;

stack<dog>st;

int n,m,T,EX,EY,SX,SY,TX,TY;

int map[30+10][30+10],dis[30+10][30+10],step[30+10][30+10][5][5],vis[30+10][30+10][5];

int dp[30+10][30+10][4];

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void pre_BFS(int sx,int sy)//预处理出(sx,sy)这个格子周围四个格子间不经过(sx,sy)的最短路 
{
	
  for(int i=0;i<4;i++)
  {
  	int xx=sx+dx[i];
  	int yy=sy+dy[i];
  	
  	if(xx>0&&yy>0&&xx<=n&&yy<=m&&map[xx][yy])
  	{
  	  st.push((dog){xx,yy,i});
  	}
  	
  }
  
  while(!st.empty())//需要一个一个处理 
  {
  
     while(!q.empty())q.pop();
  
     memset(dis,inf,sizeof(dis));
  
     int nx=st.top().x,ny=st.top().y,ret=st.top().now;
  
     dis[nx][ny]=0;
     
	 q.push((node){nx,ny});
	    
     st.pop();
  
     while(!q.empty())
     {
     	node u=q.front();q.pop();
     	
     	int x=u.x,y=u.y;
     	
     	for(int i=0;i<4;i++)
     	{
     		int xx=x+dx[i];
     		int yy=y+dy[i];
     		
     		if(xx>0&&yy>0&&xx<=n&&yy<=m&&map[xx][yy]&&(xx!=sx||yy!=sy)&&dis[xx][yy]==inf)//由于路权都为1，所以第一次到达即为最短路 
     		{
     		  dis[xx][yy]=dis[x][y]+1;
			  q.push((node){xx,yy});  
     		}
     		
     	}
     	
     }
     
     for(int i=0;i<4;i++)
     {
     	int xx=sx+dx[i];
     	int yy=sy+dy[i];
     	
     	if(xx>0&&yy>0&&xx<=n&&yy<=m&&map[xx][yy]&&(xx!=nx||yy!=ny)&&dis[xx][yy]!=inf)
     	{
     		step[sx][sy][ret][i]=dis[xx][yy];//记录最短路 
     	}
     }
     
  }
  
}

void pre_BLACK()//找当前的空格到棋子周围的空格的最短路 
{
   while(!q.empty())q.pop();
  
   memset(dis,inf,sizeof(dis));
   
   dis[EX][EY]=0;
   
   q.push((node){EX,EY});
   
   while(!q.empty())
   {
   	 node u=q.front();q.pop();
   	 
   	 for(int i=0;i<4;i++)
   	 {
   	 	int xx=u.x+dx[i];
     	int yy=u.y+dy[i];
     		
     	if(xx>0&&yy>0&&xx<=n&&yy<=m&&map[xx][yy]&&(xx!=SX||yy!=SY)&&dis[xx][yy]==inf)//不能经过(SX,SY)这个点 
     	{
     		dis[xx][yy]=dis[u.x][u.y]+1;
			q.push((node){xx,yy});
     	}
   	 }
   	 
   }
   
  /*for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
  	printf("dis[%d][%d]=%d\n",i,j,dis[i][j]);
  }*/
   
}

int BFS()//个人觉得叫SPFA()更合适些 
{
	
  if(TX==SX&&TY==SY)return 0;//起点与终点重合，返回0 
	
  pre_BLACK();//预处理 
	
  memset(dp,inf,sizeof(dp));
	
  while(!Q.empty())Q.pop();
	
  for(int i=0;i<4;i++)
  {
  	int xx=SX+dx[i];
  	int yy=SY+dy[i];
  	
  	if(xx>0&&yy>0&&xx<=n&&yy<=m&&dis[xx][yy]!=inf&&map[xx][yy])
  	{
  	  dp[SX][SY][i]=dis[xx][yy];//加入队列 
  	  Q.push((dog){SX,SY,i});
  	  vis[SX][SY][i]=1;
  	}
  	
  }
  
  while(!Q.empty())
  {
  	dog u=Q.front();Q.pop();
  	
  	vis[u.x][u.y][u.now]=0;
  	
  	/////////////////////棋子移到空格的情况 
  	
  	int xx=u.x+dx[u.now];
  	int yy=u.y+dy[u.now];
  	
  	if(dp[xx][yy][(u.now+2)%4]>dp[u.x][u.y][u.now]+1)
  	{
  	  dp[xx][yy][(u.now+2)%4]=dp[u.x][u.y][u.now]+1;
  	  if(!vis[xx][yy][(u.now+2)%4])
  	  {
  	  	vis[xx][yy][(u.now+2)%4]=1;
  	  	Q.push((dog){xx,yy,(u.now+2)%4});
  	  }
  	}
  	
  	/////////////////////棋子周围的空格互相移动的情况 
  	
  	for(int i=0;i<4;i++)
  	{
  	  xx=u.x+dx[i];
  	  yy=u.y+dy[i];
  	  
  	  if(xx>0&&yy>0&&xx<=n&&yy<=m&&map[xx][yy]&&i!=u.now&&step[u.x][u.y][u.now][i]!=inf)
  	  {
  	  	if(dp[u.x][u.y][i]>dp[u.x][u.y][u.now]+step[u.x][u.y][u.now][i])
  	  	{
  	  		dp[u.x][u.y][i]=dp[u.x][u.y][u.now]+step[u.x][u.y][u.now][i];
  	  		if(!vis[u.x][u.y][i])
  	  		{
  	  			vis[u.x][u.y][i]=1;
  	  			Q.push((dog){u.x,u.y,i});
  	  		}
  	  	}
  	  }
  	  
  	}
  	
  }
  
  int ans=inf;
  
  for(int i=0;i<4;i++)//找最短路 
  {
  	ans=min(ans,dp[TX][TY][i]);
  }
  
  if(ans==inf)return -1;//不存在 
  return ans;
  
}

int main()
{
	freopen("1846.in","r",stdin);
  scanf("%d%d%d",&n,&m,&T);
  
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
  	scanf("%d",&map[i][j]);
  }
  
  memset(step,inf,sizeof(step));
  
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
  	if(map[i][j]) pre_BFS(i,j);//预处理 
  }
  
  for(int i=1;i<=T;i++)
  {
  	scanf("%d%d%d%d%d%d",&EX,&EY,&SX,&SY,&TX,&TY);
  	printf("%d\n",BFS());
  }

  return 0;
}

