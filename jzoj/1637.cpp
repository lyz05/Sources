#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105,M = 105,INF = 1e9+7,s = 0,t = 10001;

const int MaxEdge = N*M*6,MaxNode = N*M;
struct Netflow					//�����������֮sap�㷨
{
	int TotNode;
	struct node
	{int y,next;} H[MaxEdge];		//��������
	int d[MaxNode],f[MaxEdge],E[MaxNode],final[MaxNode],gap[MaxNode];
	//d�����ţ�gap�����Ŷ�Ӧ�Ľ��ĸ���
	
	void add(int x,int y,int z)		//�ӱ�
	{
		static int tot;
		H[++ tot].y = y;
		H[tot].next = E[x];
		E[x] = tot;
		f[tot] = z;
	}

	void insert(int x,int y,int z)		//��������
	{
		add(x,y,z);add(y,x,0);	
	}
	
	int dfs(int now,int limit)		//����·
	{
		if (now==t) 
			return limit;
		int ret = 0;
		for (int i=E[now];i;i=H[i].next) if (f[i])	// ����������
		{
			E[now] = i;				//��֤��ǰ��֮ǰ����������
			int j = H[i].y;
			if (d[j]+1!=d[now]) continue;		//�Ӻ���ǰ��
			int tmp = dfs(j,min(limit-ret,f[i]));
			f[i] -= tmp;
			ret += tmp;
			if (i & 1) f[i+1] += tmp;else f[i-1] += tmp;
			//���²�������
			if (ret==limit) return ret;
		}
		E[now] = final[now];			//�ָ����
		gap[d[now]] --;
		if (!gap[d[now]]) d[s] = TotNode;	//���ֶϲ�,����ʧ��	
		gap[++ d[now]] ++;
		return ret;
	}
		
	int sap(int node)
	{
		int ans = 0;
		TotNode = node;
		memset(d,0,sizeof d);			//��վ�����
		gap[0] = TotNode;			//�������е������
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
