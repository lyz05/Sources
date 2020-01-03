#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define LiangJiaJun main
#define T 10001
#define S 0
#define INF 1999122700
using namespace std;
queue<int>q;
int n,m,map[104][104];
int h[10004],dis[10004],ne=1;

struct edge{int to,next,w;}e[1990004];
void add(int u,int v,int w){
     e[++ne].to=v;e[ne].w=w;
     e[ne].next=h[u];
     h[u]=ne;
}
void insert(int u,int v,int w){add(u,v,w);add(v,u,0);}
bool bfs(){
     memset(dis,-1,sizeof(dis));
     dis[S]=0;q.push(S);
     while(!q.empty()){
         int x=q.front();q.pop();
         for(int i=h[x];i;i=e[i].next){
            if(e[i].w&&dis[e[i].to]==-1){
                dis[e[i].to]=dis[x]+1;
                q.push(e[i].to);//cout<<1<<endl;
            }
         }
     }
     if(dis[T]==-1)return 0;
     return 1;
}
int dfs(int x,int f){
    if(x==T)return f;
    int w,used=0;
    for(int i=h[x];i;i=e[i].next)
        if(e[i].w&&dis[e[i].to]==dis[x]+1){
            w=dfs(e[i].to,min(e[i].w,f-used));
            used+=w;e[i].w-=w;e[i^1].w+=w;
            if(used==f)return f;
        }
    if(!used)dis[x]=-1;
    return used;
}
int dinic(){
    int ans=0;
    while(bfs())ans+=dfs(S,INF);
    return ans;
}
int LiangJiaJun(){
	freopen("1637.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)scanf("%d",&map[i][j]);

     for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
               if(map[i][j]==1)insert(S,(i-1)*m+j,INF);
               if(map[i][j]==2)insert((i-1)*m+j,T,INF);
               if(map[i][j]==1||map[i][j]==0){
                    if(i-1>0){
                         if(map[i-1][j]==2||map[i-1][j]==0){
                              insert((i-1)*m+j,(i-2)*m+j,1);
                         }
                    }
                    if(j-1>0){
                         if(map[i][j-1]==2||map[i][j-1]==0)  {
                              insert((i-1)*m+j,(i-1)*m+j-1,1);
                         }
                    }
                    if(i+1<=n){
                         if(map[i+1][j]==2||map[i+1][j]==0){
                              insert((i-1)*m+j,i*m+j,1);
                         }
                    }
                    if(j+1<=m){
                         if(map[i][j+1]==2||map[i][j+1]==0){
                              insert((i-1)*m+j,(i-1)*m+j+1,1);
                         }
                    }
               }
          }
    }
    printf("%d\n",dinic());
    return 0;
}
