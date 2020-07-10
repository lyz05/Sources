#include<stdio.h>
#include<string.h>
#define M 107
using namespace std;
int vis[M],g[M][M],link[M];
int n,m;
 
bool find(int i)
{
    for(int j=1;j<=m;j++)
        if(!vis[j]&&g[i][j])
        {
            vis[j]=1;
            if(link[j]==0||find(link[j]))
            {
                link[j]=i;
                return true;
            }
        }
    return false;
}
 
int main()
{
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        int a,count=0;
        memset(g,0,sizeof(g));
        memset(link,0,sizeof(link));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a);
                if(a==1)
                    g[i][j]=1;
            }
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i))
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
