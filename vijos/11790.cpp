#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1010],n,m,arr[11000],cnt,answer[1100];
int cal(int num)
{
    if(!num)return 0;
    for(int i=0;i<1010;i++)dp[i]=100000;
    dp[0]=0;
    int x=0;
    while(dp[x]<=n)
    {
        for(int i=1;i<=num;i++)
        {
            dp[x+arr[i]]=min(dp[x+arr[i]],dp[x]+1);
        }
	x++;
    }return x-1;
}
void dfs(int x)
{
    if(x>m)
    {
        int now=cal(x-1);
        if(now>cnt)
        {
            cnt=now;
            for(int i=1;i<=m;i++)
            {
                answer[i]=arr[i];
            }
        }
    }
    else
    {
        int now=cal(x-1);
        for(int i=now+1;i>=arr[x-1];i--)
        {
            arr[x]=i;
            dfs(x+1);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    dfs(1);
    for(int i=1;i<m;i++)
    {
        printf("%d ",answer[i]);
    }
    printf("%d\n",answer[m]);
    printf("MAX=%d",cnt);
    return 0;
}    
