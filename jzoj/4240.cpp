#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 900000+5;

struct node
{
	int l,r;
} T[N];

int n;
int e[N],next[5*N],to[5*N];
int fa[N][21],dep[N],Cnt[N],rd[N],stack[N],Q[N];
int ord[N],a[N],l[N],r[N],cnt;
int tot,m,maxl;
bool vis[N];

void add(int x,int y)
{
	to[++ tot] = y;next[tot] = e[x];e[x] = tot;
}

void bfs()
{
	int l=0,r=1;Q[1] = 1;
	while (l<r)
	{
		int u = Q[++ l];
		vis[u] = 1;
		for (int j=e[u];j;j=next[j])
		{
			rd[to[j]] ++;
			if (!vis[to[j]]) vis[to[j]]=1,Q[++ r] = to[j];
		}
	}
}

int LCA(int x,int y)
{
	if (dep[x]>dep[y]) swap(x,y);
	for (int i=maxl;i>=0;i --) 
		if (dep[fa[y][i]]>=dep[x]) y = fa[y][i];
	if (x==y) return x;
	for (int i=maxl;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x = fa[x][i],y = fa[y][i];
	return fa[y][0];
}

void work()
{
	bfs();
	int top = 1;
	stack[1] = 1;
	for (;;maxl ++) if ((1 << maxl) > m) break;

	while (top)
	{
		int x = stack[top --];
		dep[x] = dep[fa[x][0]] + 1;
		Cnt[x] = Cnt[fa[x][0]] + (x<=n);
		for (int i=1;i<=maxl;i ++)
			fa[x][i] = fa[fa[x][i-1]][i-1];
		for (int i=e[x];i;i = next[i])
		{
			int y=to[i];
			if (!fa[y][0]) fa[y][0] = x; 
			else fa[y][0] = LCA(fa[y][0],x);
			if (!(-- rd[y])) stack[++ top] = y;
		}
	}
}



void add_edge(int u,int l,int r,int st,int en,int jd)
{
	if (!jd) return; //当前线段树结点，无对应虚拟点
	if (en<l || st>r) return;
	if (st <=l && r <= en)
	{
		add(u,n+jd);
		return;
	}
	int mid = (l+r) >> 1;
	add_edge(u,l,mid,st,en,T[jd].l);
	add_edge(u,mid+1,r,st,en,T[jd].r);
}

int add_point(int l,int r,int p,int jd,int v)//返回当前线段树对应的虚拟点
{
	int tn = ++ cnt;
	T[tn] = T[jd];
	if (jd) add(tn + n,jd + n);	//新结点连向旧结点
	add(tn + n,v);			//新结点连向中点
	if (l==r) return tn;
	int mid = (l+r)>>1;
	if (p <= mid) T[tn].l = add_point(l,mid,p,T[jd].l,v); else 
		T[tn].r = add_point(mid+1,r,p,T[jd].r,v);
	return tn;
}

int main()
{
	freopen("4240.in","r",stdin);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",a + i);
	for (int i=1;i<=n;i ++) scanf("%d%d",l + i,r + i);

	for (int i=n;i;i --)	//ord 根节点
	{
		add_edge(i,1,n,l[i],r[i],ord[i+1]);
		ord[i] = add_point(1,n,a[i],ord[i+1],i);
	}
	m = n + cnt;
	work();
	for (int i=1;i<=n;i ++)
		if (dep[i]) printf("%d\n",Cnt[i]);
		else printf("-1\n");
	return 0;
}
