#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105,M = 105,INF = 1e9+7,s = 0,t = 10001;

const int MaxEdge = N*M*6,MaxNode = N*M;
struct Netflow					//网络流最大流之sap算法
{
	int TotNode;
	struct node
	{int y,next;} H[MaxEdge];		//网络流边
	int d[MaxNode],f[MaxEdge],E[MaxNode],final[MaxNode],gap[MaxNode];
	//d距离标号，gap距离标号对应的结点的个数
	
	void add(int x,int y,int z)		//加边
	{
		static int tot;
		H[++ tot].y = y;
		H[tot].next = E[x];
		E[x] = tot;
		f[tot] = z;
	}

	void insert(int x,int y,int z)		//残量网络
	{
		add(x,y,z);add(y,x,0);	
	}
	
	int dfs(int now,int limit)		//增广路
	{
		if (now==t) 
			return limit;
		int ret = 0;
		for (int i=E[now];i;i=H[i].next) if (f[i])	// 还能流流量
		{
			E[now] = i;				//保证当前弧之前不存在允许弧
			int j = H[i].y;
			if (d[j]+1!=d[now]) continue;		//从后往前走
			int tmp = dfs(j,min(limit-ret,f[i]));
			f[i] -= tmp;
			ret += tmp;
			if (i & 1) f[i+1] += tmp;else f[i-1] += tmp;
			//更新残量网络
			if (ret==limit) return ret;
		}
		E[now] = final[now];			//恢复标号
		gap[d[now]] --;
		if (!gap[d[now]]) d[s] = TotNode;	//出现断层,增广失败	
		gap[++ d[now]] ++;
		return ret;
	}
		
	int sap(int node)
	{
		int ans = 0;
		TotNode = node;
		memset(d,0,sizeof d);			//清空距离标号
		gap[0] = TotNode;			//网络流中点的总数
		for (int i=s;i<=t;i ++) final[i] = E[i];
		while (d[s]<TotNode) 
			ans += dfs(s,INF);
		return ans;
	}
} netflow;

const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,ans;
int map[N][M];

int calc(int x,int y)
{
	return (x-1)*m+y;
}

int main()
{
	freopen("1637.in","r",stdin);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
			scanf("%d",&map[i][j]);

	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
		{
			if (map[i][j]==1) netflow.insert(s,calc(i,j),INF);
			if (map[i][j]==2) netflow.insert(calc(i,j),t,INF);
			if (map[i][j]==1 || map[i][j]==0)
			for (int k=0;k<4;k ++)
			{
				int tx=i+dir[k][0],ty=j+dir[k][1];
				if (tx>0&&ty>0&&tx<=n&&ty<=m&&(map[tx][ty]==2||map[tx][ty]==0))
				{
					netflow.insert(calc(i,j),calc(tx,ty),1);
				}
			}
		}
	ans = netflow.sap(2+n*m);
	printf("%d\n",ans);
	return 0;
}
