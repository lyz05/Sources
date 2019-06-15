//拓扑排序算法
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000000+5,M = 1000000+5;
struct node
{
	int y,next;
} h[M];						//模拟链表 
int n,m,tot,l,r,cnt;
int e[N],list[N],rd[N];

void add(int x,int y)		//添加一条边 
{
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
	rd[y] ++;
}

int main()
{
	//freopen("mikado.in","r",stdin);
	//freopen("mikado.out","w",stdout);

	printf("请输入顶点总数和边总数\n"); 
	scanf("%d%d",&n,&m);		 
	for (int i=1;i<=m;i ++)
	{
		int u,v;
		printf("请输入第%d条边（用空格隔开）",i);
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	 
	l = 1;r = 0;
	for (int i=1;i<=n;i ++)
		if (!rd[i]) list[++ r] = i;
	//寻找入度为0的点加入到队列中 
	while (l<=r)
	{
		int now = list[l ++];
		//cnt ++;
		for (int i=e[now];i;i=h[i].next)
		{
			int y = h[i].y;
			rd[y] --;
			if (!rd[y]) list[++ r] = y;
		} 
	}
	if (l<n) printf("存在回路\n");
	else
	{
		printf("拓扑排序序列：");
		for (int i=1;i<l;i ++) 
			printf("%d ",list[i]);
		printf("\n");
	}
	return 0;
}
