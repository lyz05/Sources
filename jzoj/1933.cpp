#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define For for (int i=1;i<=n;i ++) for (int j=1;j<=m;j ++)
using namespace std;

const int N = 105,M = 105,INF = 1e9+7;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m,s,t,sum,ans;
int a[N][M],b[N][M],c[N][M],color[N][M];

int calc(int x,int y) {return (x-1)*m+y;}

const int MaxEdge = N*M*8,MaxNode = N*M+2;
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

void build()
{
	s = 0,t = n*m+1;
	For
	{
		if (color[i][j]) swap(a[i][j],b[i][j]);
		netflow.insert(s,calc(i,j),a[i][j]);sum += a[i][j];
		netflow.insert(calc(i,j),t,b[i][j]);sum += b[i][j];
		if (color[i][j])
			for (int k=0;k<4;k ++)
			{
				int tx = i+dir[k][0],ty = j+dir[k][1],w = c[i][j]+c[tx][ty];
				if (tx<1 || ty<1 || tx>n || ty>m) continue;
				netflow.insert(calc(i,j),calc(tx,ty),w);
				netflow.insert(calc(tx,ty),calc(i,j),w);
				sum += w;
			}
	}	
}

int main()
{
	freopen("1933.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&m);
	For scanf("%d",&a[i][j]);
	For scanf("%d",&b[i][j]);
	For scanf("%d",&c[i][j]);
	For if ((i+j)&1) color[i][j] = 1;
	build();
	ans = sum - netflow.sap(t+1);
	printf("%d\n",ans);
	return 0;
}
