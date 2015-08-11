#include<stdio.h>
#include<string.h>
int st[3000][2];
int dp[11][3000]; //2^11=2048最多的状态数
int cnt,h,w;
void dfs(int n,int from,int to)//枚举所有一行摆放的可能和其匹配的下层
{
    if(n>w)
        return;
    if(n==w)  //这一行刚好摆完，得到一行摆放的组合
    {
        st[cnt][0]=from;
        st[cnt][1]=to;
        cnt++;
        return;
    }
    dfs(n+2,(from<<2)+3,(to<<2)+3); //横着放，这层和下一层匹配的都多两位1
    dfs(n+1,(from<<1)+1,to<<1);//竖着放，这层多一个1,匹配下层这个位置是0
    dfs(n+1,from<<1,(to<<1)+1);//不放，这层多一个0，匹配的下层多个1

}
int main()
{
    int i,j;
    while(scanf("%d %d",&h,&w)&&h)
    {
        if((w*h)%2)
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        memset(st,0,sizeof(st));
        cnt=0; //记录每一行摆放所有可能的状态总数
        dfs(0,0,0);
        dp[0][(1<<w)-1]=1;//边界
        for(i=1;i<=h;i++)
        {
            for(j=0;j<cnt;j++)
            {
                dp[i][st[j][1]]+=dp[i-1][st[j][0]];
            }
        }
        printf("%d\n",dp[h][(1<<w)-1]);
    }
    return 0;
}

