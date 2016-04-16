#include<iostream>
#include<cstring>
#include<cstdio>
#define T 10001
#define inf 0x7fffffff
#define FOR for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
using namespace std;
int n,m,cnt=1,tot,ans,head[10001],h[10002];
int a[101][101],b[101][101],c[101][101];
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
int color[101][101];
struct data{int to,next,v;}e[100001];
void ins(int u,int v,int w)
{cnt++;e[cnt].to=v;e[cnt].v=w;e[cnt].next=head[u];head[u]=cnt;}
void insert(int u,int v,int w)
{tot+=w;ins(u,v,w);ins(v,u,0);}
bool bfs()
{
     int q[10005],t=0,w=1,i,now;
     memset(h,-1,sizeof(h));
     q[0]=h[0]=0;
     while(t!=w)
     {
            now=q[t];t++;if(t==10001)t=0;
            for(i=head[now];i;i=e[i].next)
            {
                  if(e[i].v&&h[e[i].to]<0)
                        {h[e[i].to]=h[now]+1;q[w++]=e[i].to;if(w==10001)w=0;}
             }
     }
     if(h[T]==-1)return 0;return 1;
     }
int dfs(int x,int f)
{
    if(x==T)return f;
    int w,used=0;
    for(int i=head[x];i;i=e[i].next)
    {
            if(e[i].v&&h[e[i].to]==h[x]+1)
            {
                w=f-used;
                w=dfs(e[i].to,min(w,e[i].v));   
                e[i].v-=w;e[i^1].v+=w;
                used+=w;if(used==f)return f;                      
                }
            }
    if(!used)h[x]=-1;
    return used;
    }
void dinic(){while(bfs())ans+=dfs(0,inf);}
void build()
{
	FOR{
	   	   if(color[i][j])swap(a[i][j],b[i][j]);
		   insert(0,(i-1)*m+j,a[i][j]);
		   insert((i-1)*m+j,T,b[i][j]);
		   if(color[i][j])
	          for(int k=0;k<4;k++)
	          {
	      	  	  int nowx=i+xx[k],nowy=j+yy[k];
	      	  	  if(nowx>n||nowy>m||nowx<1||nowy<1)continue;
	      	      ins((i-1)*m+j,(nowx-1)*m+nowy,c[i][j]+c[nowx][nowy]);
	      	      ins((nowx-1)*m+nowy,(i-1)*m+j,c[i][j]+c[nowx][nowy]);
	         	  tot+=(c[i][j]+c[nowx][nowy]);
	          }
	   }
}
int main()
{
	freopen("1933.in","r",stdin);
	scanf("%d%d",&n,&m);
	FOR scanf("%d",&a[i][j]);
	FOR scanf("%d",&b[i][j]);
	FOR scanf("%d",&c[i][j]);
	FOR if((i+j)&1)color[i][j]=1;
	build();dinic();
	printf("%d",tot-ans);
	return 0;
}
