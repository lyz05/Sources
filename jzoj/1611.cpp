#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105;
int n,tot1,tot2,s,t,ans;

const int MaxEdge = 2*(3*N+2*N*N),MaxNode = 4*N+2,INF = 1e9+7;
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

int main()
{
	freopen("1611.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d%d",&n,&tot1,&tot2);
	s = 0,t = 2*n+tot1+tot2+1;
	for (int i=1;i<=n;i ++) 
		netflow.insert(i,n+i,1);
	for (int i=1;i<=tot1;i ++)
		netflow.insert(0,2*n+i,1);
	for (int i=1;i<=tot2;i ++)
		netflow.insert(2*n+tot1+i,t,1);
	for (int i=1;i<=n;i ++)
	{
		int x,y,t;
		scanf("%d%d",&x,&y);
		for (int j=1;j<=x;j ++) 
			scanf("%d",&t),netflow.insert(2*n+t,i,1);
		for (int j=1;j<=y;j ++) 
			scanf("%d",&t),netflow.insert(n+i,2*n+tot1+t,1);
	}
	ans = netflow.sap(t+1);
	printf("%d\n",ans);

	return 0;
}
