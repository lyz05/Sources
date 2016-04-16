#include <stdio.h>
#define MAXN 3000
int f[MAXN][MAXN],sum[MAXN]; //f[i][j]=该行前i个格子刷j次最多的正确格子数,sum[i]=该行前i个格子是1的格子的数目
int dp[MAXN][MAXN]; //dp[i][j]=前i行刷了j次的最多正确格子数
char in[MAXN];
int max(int a,int b)
{
  if(a>b) return a;
  return b;
}
int min(int a,int b)
{
  if(a<b) return a;
  return b;
}
int main()
{
  int k,i,j,n,m,t,l,ans=-1;
  scanf("%d%d%d",&n,&m,&t);
  for(k=1;k<=n;k++)
  {
    scanf("%s",in+1);
    for(i=1;i<=m;i++)
      sum[i]=sum[i-1]+(in[i]=='1');
    for(i=1;i<=m;i++)
      for(j=1;j<=m;j++)
      {
        f[j][i]=0;
        for(l=0;l<j;l++)
        {
          int cnt=sum[j]-sum[l]; //区间[l,j]中是1的个数
          f[j][i]=max(f[j][i],f[l][i-1]+max(cnt,j-l-cnt)); //max(cnt,j-l-cnt):取刷0或刷1的正确格子数最大值
        }
      }
    for(i=1;i<=t;i++)
    {
      int cnt=min(m,i); //cnt=实际粉刷次数
      for(j=1;j<=cnt;j++)
        dp[k][i]=max(dp[k][i],dp[k-1][i-j]+f[m][j]); //背包
    }
  }
  for(i=1;i<=t;i++)
    ans=max(ans,dp[n][i]);
  printf("%d\n",ans);
  return 0;
}
