#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int N = 50+5, M = 500+5,INF = 1e9+7;
int n,m,ans,tot;
int vis[N],e[N];

struct edge
{
	int to,next,c;
} h[2*M];

struct node
{
	int id,c;
} a[N];

bool cmp(node A,node B)
{
	return A.c>B.c;
}

void add(int x,int y,int val)
{
	tot ++;
	h[tot].to = y;
	h[tot].next = e[x];
	h[tot].c = val;
	e[x] = tot;
}

void dfs(int dep,int sum)
{
	if (dep>n)
	{
		ans = min(ans,sum);
		return;
	}

	int u = a[dep].id,tmp = 0;
	vector <int> st;
	if (vis[u]) 
	{
		dfs(dep+1,sum);
		return;
	}
	vis[u] = 1;
	for (int i=0;i<=1;i ++)
	{
		if (i==0)
		{
			for (int j=e[u];j;j=h[j].next)
			{
				int v = h[j].to;
				if (!vis[v]) 
				{
					vis[v] = 1;
					tmp += h[j].c;
					st.push_back(v);
				}
			}		
		} else 
		{
			while (!st.empty()) 
				vis[st.back()] = 0, st.pop_back();
			tmp = a[dep].c;
		}
		dfs(dep+1,sum + tmp);
	}
	vis[u] = 0;
}

int main()
{
	freopen("graph.in","r",stdin);
	//freopen("graph.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++) 
		scanf("%d",&a[i].c) , a[i].id = i;
	for (int i=1;i<=m;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,a[v].c);add(v,u,a[u].c);
	}

	sort(a + 1,a + 1 + n,cmp);
	ans = INF;
	dfs(1,0);
	printf("%d\n",ans);
	
	return 0;
}
