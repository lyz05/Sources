#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 100000+5;
int n,now,ans,tmp;
int e[N],vis[N],dis[N];
struct node
{int y,z,id,next;} h[2*N];

void add(int x,int y,int z,int id)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].next = e[x];
	h[tot].id = id;
	h[tot].z = z;
	e[x] = tot;
}


void bfs(int x,int &rety,int &dist)
{
	dist = 0;
	static queue <int> q; 
	memset(vis,0,sizeof vis);
	vis[x] = 1;
	dis[x] = 0;
	rety = x;
	q.push(x);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=e[x];i;i=h[i].next)
		{
			if (h[i].id==now) continue;
			int y = h[i].y;
			if (!vis[y]) 
			{
				dis[y] = dis[x]+h[i].z;
				vis[y] = 1;
				if (dis[y]>dist)
				{
					dist = dis[y];
					rety = y;
				}
				q.push(y);
			}
		}
	}
}

int getdis(int x)
{
	int y,dis;
	bfs(x,y,dis);
	bfs(y,x,dis);
	return dis;
}

int main()
{
	freopen("data.in","r",stdin);
	//freopen("1737.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<n;i ++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,i);add(y,x,z,i);
	}
	for (now=1;now<n;now ++)
	{
		tmp = 0;int flag = 2;
		for (int i=1;i<=n;i ++)
			if (!vis[i] && flag) tmp += getdis(i),flag --;
		ans = max(ans,tmp);
	}
	printf("%d\n",ans);
	return 0;
}
