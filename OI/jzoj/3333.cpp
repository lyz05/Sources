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
struct Netflow					//�����������֮sap�㷨
{
	int TotNode;				//�������еĵ���
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
			if (ret==limit) return ret;		//�Ѿ���������
		}
		E[now] = final[now];			//�ָ����
		gap[d[now]] --;
		if (!gap[d[now]]) d[s] = TotNode;	//���ֶϲ�,����ʧ��	
		gap[++ d[now]] ++;
		return ret;
	}
		
	int sap(int node)				//O(N^2*M)
	{
		int ans = 0;
		TotNode = node;
		memset(d,0,sizeof d);			//��վ�����
		gap[0] = TotNode;			//�������е������
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
