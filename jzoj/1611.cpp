#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105;
int n,tot1,tot2,s,t,ans;

const int MaxEdge = 2*(3*N+2*N*N),MaxNode = 4*N+2,INF = 1e9+7;
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
