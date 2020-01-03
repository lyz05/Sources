#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

struct node1
{
	int x,y,now;
};
struct node
{
	int x,y;
};
const int inf = 0x3f3f3f3f,N = 35,M = 35,
      dx[]={0,1,0,-1},dy[]={1,0,-1,0};

queue<node>q;
queue<node1>Q;
stack<node1>st;

int map[N][M],dis[N][M],step[N][M][5][5],vis[N][M][5];
int dp[N][M][5];
int n,m,T,EX,EY,SX,SY,TX,TY;

bool judge(int x,int y)
{
	return x>0&&y>0&&x<=n&&y<=m&&map[x][y];
}

void pre_bfs(int sx,int sy)//Ԥ�����(sx,sy)���������Χ�ĸ����Ӽ䲻����(sx,sy)�����· 
{
	for(int i=0;i<4;i++)
	{
	  	int xx=sx+dx[i];
	  	int yy=sy+dy[i];
	  	
	  	if(judge(xx,yy)) st.push((node1){xx,yy,i});
	}
  
	while(!st.empty())//��Ҫһ��һ������ 
	{
		while (!q.empty()) q.pop();
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
				int xx=x+dx[i],yy=y+dy[i];	
				if(judge(xx,yy)&&(xx!=sx||yy!=sy)&&dis[xx][yy]==inf)//����·Ȩ��Ϊ1�����Ե�һ�ε��ＴΪ���· 
				{
					dis[xx][yy]=dis[x][y]+1;
					q.push((node){xx,yy});  
				}
     		
			}
		     	
		}

		for(int i=0;i<4;i++)
		{
			int xx=sx+dx[i],yy=sy+dy[i];
			if(judge(xx,yy)&&(xx!=nx||yy!=ny)&&dis[xx][yy]!=inf)
				step[sx][sy][ret][i]=dis[xx][yy];//��¼���· 

		}
     
	}
  
}

void pre_black()//�ҵ�ǰ�Ŀո�������Χ�Ŀո�����· 
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
   	 		int xx=u.x+dx[i],yy=u.y+dy[i];
     		
     			if(judge(xx,yy)&&(xx!=SX||yy!=SY)&&dis[xx][yy]==inf)//���ܾ���(SX,SY)����� 
     			{
     				dis[xx][yy]=dis[u.x][u.y]+1;
				q.push((node){xx,yy});
     			}
   		}
   	 }
}


int spfa()
{
	if (TX==SX&&TY==SY) return 0;//������յ��غ�
	pre_black();
	memset(dp,inf,sizeof dp);
	while (!Q.empty()) Q.pop();

	for (int i=0;i<4;i ++)
	{
		int xx = SX+dx[i],yy = SY+dy[i];
		if (judge(xx,yy) && dis[xx][yy]!=inf)
		{
			dp[SX][SY][i] = dis[xx][yy];
			Q.push((node1){SX,SY,i});
			vis[SX][SY][i] = 1;
		}
	}
	while (!Q.empty())
	{
		node1 u=Q.front();Q.pop();
		vis[u.x][u.y][u.now] = 0;

		//�����Ƶ��ո�����
		
		int xx = u.x+dx[u.now],yy = u.y+dy[u.now];
  		if(dp[xx][yy][(u.now+2)%4]>dp[u.x][u.y][u.now]+1)
		{
			dp[xx][yy][(u.now+2)%4]=dp[u.x][u.y][u.now]+1;
			if(!vis[xx][yy][(u.now+2)%4])
			{
				vis[xx][yy][(u.now+2)%4]=1;
				Q.push((node1){xx,yy,(u.now+2)%4});
			}
		}
		
		//������Χ�Ŀո����ƶ������ 
		for(int i=0;i<4;i++)
		{
			xx=u.x+dx[i];yy=u.y+dy[i];
			if(judge(xx,yy)&&i!=u.now&&step[u.x][u.y][u.now][i]!=inf)
			if(dp[u.x][u.y][i]>dp[u.x][u.y][u.now]+step[u.x][u.y][u.now][i])
  	  		{
  	  			dp[u.x][u.y][i]=dp[u.x][u.y][u.now]+step[u.x][u.y][u.now][i];
  	  			if(!vis[u.x][u.y][i])
  	  			{
  	  				vis[u.x][u.y][i]=1;
  	  				Q.push((node1){u.x,u.y,i});
  	  			}
  	  		}
  		}
	}
	int ans=inf;
	for(int i=0;i<4;i++)//�����·
		ans=min(ans,dp[TX][TY][i]);
  	
	if (ans==inf) return -1;//������ 
	return ans;
}

int main()
{
	freopen("1846.in","r",stdin);
	//freopen("1846.out","w",stdout);

	scanf("%d%d%d",&n,&m,&T);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=m;j ++) 
		scanf("%d",&map[i][j]);
	memset(step,inf,sizeof step);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=m;j ++)
		if (map[i][j]) pre_bfs(i,j);
	while (T --)
	{
		scanf("%d%d%d%d%d%d",&EX,&EY,&SX,&SY,&TX,&TY);
		printf("%d\n",spfa());
	}

	return 0;
}
