#include <cstdio>
#include <cstring>

using namespace std;

const int N=13;

int val[N];
bool map[N][N];
int dp[1<<N][N][N];
long long num[1<<N][N][N];
int n,m;


bool init()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d",&val[i]);
	memset(map,0,sizeof map);
	int u,v;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		u--;v--;
		map[u][v]=map[v][u]=1;
	}
	if (n==1) //???dp???????
	{
		printf("%d 1\n",val[0]);
		return 1;
	}
	memset(dp,-1,sizeof dp);
	memset(num,0,sizeof num);
	return 0;
}

void prepar()
{
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (i!=j && map[i][j]){
                    dp[(1<<i)|(1<<j)][i][j]=val[i]+val[j]+val[i]*val[j];
                    num[(1<<i)|(1<<j)][i][j]=1;
                }
	//?????????
}

void work()
{
	//???????????????????????
	//????????
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)
		if((i&(1<<j))!=0)//??????????
			for(int k=0;k<n;k++)
                        if(map[j][k] && j!=k && (i&(1<<k))!=0 && dp[i][j][k]!=-1)
			//????????
				for(int x=0;x<n;x++)
                                if(map[k][x] && j!=x && k!=x && (i&(1<<x))==0){
                                    int tmp=dp[i][j][k]+val[x]+val[k]*val[x];
                                    if(map[j][x])
                                        tmp+=val[j]*val[k]*val[x];
				    //??tmp?
                                    if(dp[i|(1<<x)][k][x]<tmp){
                                        dp[i|(1<<x)][k][x]=tmp;
                                        num[i|(1<<x)][k][x]=num[i][j][k];
                                    }else if(dp[i|(1<<x)][k][x]==tmp)
                                        num[i|(1<<x)][k][x]+=num[i][j][k];
				    //??dp??
                                }
}

void print()
{
        int ans1=0;
        long long ans2=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j && map[i][j]){
                    if(ans1<dp[(1<<n)-1][i][j]){
                        ans1=dp[(1<<n)-1][i][j];
                        ans2=num[(1<<n)-1][i][j];
                    }else if(ans1==dp[(1<<n)-1][i][j])
                        ans2+=num[(1<<n)-1][i][j];
                }
	printf("%d %lld\n",ans1,ans2/2);
}

int main()
{
	//freopen("1769.in","r",stdin);freopen("1769.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		if (init()) continue;
		prepar();
		work();
		print();
	}
	return 0;
}
