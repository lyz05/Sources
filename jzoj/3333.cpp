#include <cstdio>
#include <algorithm>
#include <cstring>
#define FOR for (int i=1;i<=n;i ++) for (int j=1;j<=m;j ++)
using namespace std;

const int N = 105,INF = 1e9+7,M = N;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m,s,t,sum,ans;
int c[N][N],w[N][N];


const int MaxEdge = 2*(N*M*6),MaxNode = N*M*2+2;	
struct Netflow					//网络流最大流之sap算法
{
	int TotNode;				//网络流中的点数
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
			if (ret==limit) return ret;		//已经流满流量
		}
		E[now] = final[now];			//恢复标号
		gap[d[now]] --;
		if (!gap[d[now]]) d[s] = TotNode;	//出现断层,增广失败	
		gap[++ d[now]] ++;
		return ret;
	}
		
	int sap(int node)				//O(N^2*M)
	{
		int ans = 0;
		TotNode = node;
		memset(d,0,sizeof d);			//清空距离标号
		gap[0] = TotNode;			//网络流中点的总数
		memcpy(final,E,sizeof E);
		while (d[s]<TotNode) 
			ans += dfs(s,INF);
		return ans;
	}
} netflow;


int main()
{
	freopen("3333.in","r",stdin);

	scanf("%d%d",&n,&m);
	s = 0,t = n*m*2+1;
	FOR scanf("%d",&c[i][j]);
	FOR scanf("%d",&w[i][j]),sum += w[i][j];
	FOR 
	{
		int id = (i-1)*m+j;
		netflow.insert(id,id+n*m,w[i][j]);
		if ((i+j)&1)
		{
			netflow.insert(s,id,c[i][j]);
			for (int k=0;k<4;k ++)
			{
				int x=i+dir[k][0],y=j+dir[k][1],id1=(x-1)*m+y;
				if (x<1 || y<1 || x>n || y>m) continue;
				netflow.insert(id,id1,INF);
				netflow.insert(id+n*m,id1+n*m,INF);
			}
		} else 
		{
			netflow.insert(id+n*m,t,c[i][j]);
		}
	}
	ans = sum - netflow.sap(t+1);
	printf("%d\n",ans);
	return 0;
}
