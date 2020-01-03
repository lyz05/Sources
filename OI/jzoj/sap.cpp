const int MaxEdge = 1000,MaxNode = 100;	
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

