#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 5005,INF = 1e9+7;
int n,m,k,s,t,ans;

const int MaxEdge = 2*(4*N+N*1000),MaxNode = 2*N+2;
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
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);

	scanf("%d%d%d",&n,&m,&k);
	s = 0,t = n+k+1;
	for (int i=1;i<=n;i ++) 
	{	
		int x;
		scanf("%d",&x);ans += x;
		netflow.insert(s,i,x);
	}
	for (int i=1;i<=n;i ++)
	{
		int x;
		scanf("%d",&x);ans += x;
		netflow.insert(i,t,x);
	}
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		netflow.insert(x,y,z);
		netflow.insert(y,x,z);
	}
	for (int i=1;i<=k;i ++)
	{
		int tot,kind,w,x;
		scanf("%d%d%d",&tot,&kind,&w);ans += w;
		if (kind)
		{
			netflow.insert(n+i,t,w);
			for (int j=1;j<=tot;j ++)
			{
				scanf("%d",&x);
				netflow.insert(x,n+i,INF);
			}
		} else 
		{
			netflow.insert(s,n+i,w);
			for (int j=1;j<=tot;j ++)
			{
				scanf("%d",&x);
				netflow.insert(n+i,x,INF);
			}
		}
	}
	ans -= netflow.sap(t+1);
	printf("%d\n",ans);
	return 0;
}
