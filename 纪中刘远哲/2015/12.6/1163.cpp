#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 100005,M = 100005,K = 10005;
struct Edge
{
	int y,len,next;
} h[M];

struct node
{
	int len,x;
	friend bool operator<(node x,node y)
	{
		return x.len>y.len;
	}
	node(int a,int b){x = a,len = b;}
};

priority_queue <node> Q;
int n,m,k,ans;
int e[N];

void add(int x,int y,int z)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].next = e[x];
	h[tot].len = z;
	e[x] = tot;
}

int bfs(int x)
{
	node now = node(x,0);
	Q.push(now);
	while (!Q.empty())
	{
		now = Q.top();Q.pop();
		if (now.x==n) 
		{
			k --;
			if (k==0) return now.len;
		}
		for (int i=e[now.x];i;i = h[i].next)
		{
			int y = h[i].y;
			node next = node(y,now.len+h[i].len);
			Q.push(next);
		}
	}
	return -1;
}

int main()
{
	freopen("1163.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	ans = bfs(1);
	printf("%d\n",ans);

	return 0;
}
