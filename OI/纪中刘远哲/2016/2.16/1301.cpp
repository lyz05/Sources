#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int N = 10005;
int n;
int e[N],f[N],fa[N];
struct node
{int y,next;} h[2*N];
vector <int> a;


void add(int x,int y)
{
	static int tot;
	h[++ tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
}

void dfs(int x)
{
	f[x] = 1;
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y;
		if (fa[x] == y) continue;
		fa[y] = x;
		dfs(y);
		f[x] += f[y];
	}
}

void work(int x)
{
	bool flag = 1;
	for (int i=e[x];i;i = h[i].next)
	{
		int y = h[i].y,tmp = f[y];
		if (fa[x] == y) continue;
		if (f[y]>n/2) flag = 0;
		f[x] = f[x]-f[y];
		f[y] = n;
		//fa[y] = 0;
		//fa[x] = y;
			work(y);
		//fa[x] = 0;
		//fa[y] = x;
		f[x] = n;
		f[y] = tmp;
	}
	if (flag && f[fa[x]]<=n/2) a.push_back(x);
}

int main()
{
	freopen("1301.in","r",stdin);
	//freopen("1301.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<n;i ++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1);
	work(1);
	sort(a.begin(),a.end());
	if (!a.size()) printf("NONE\n"); else 
		for (int i=0;i<a.size();i ++) printf("%d\n",a[i]);
	return 0;
}
