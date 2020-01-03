#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 900005;

int N;

namespace Domin
{
	bool Walk[MAXN];
	int Final[MAXN],Fa[MAXN][21],Deep[MAXN],Cnt[MAXN],Rd[MAXN],Stack[MAXN],Q[MAXN],tot,M,MaxL;
	int Next[MAXN * 5],To[MAXN * 5];

	void Link(int u,int v)
	{
		To[++ tot] = v,Next[tot] = Final[u],Final[u] = tot;
	}

	int Merge(int u,int v)		//Lca
	{
		if (Deep[u] > Deep[v]) swap(u,v);
		//Deep[u]<Deep[v]
		for(int i = MaxL;i >= 0;i --)
			if (Deep[Fa[v][i]] >= Deep[u]) v = Fa[v][i];
		if (u == v) return u;
		//调整至同一深度
		for(int i = MaxL;i >= 0;i --)
		if (Fa[v][i] != Fa[u][i]) v = Fa[v][i],u = Fa[u][i];
		return Fa[v][0];
	}

	void Bfs()
	{	
		int fi = 0,en = 1;Q[1] = 1;
		while (fi < en)
		{
			int u = Q[++ fi];		//bfs队列
			Walk[u] = 1;			//vis数组
			for(int j = Final[u];j;j = Next[j])
			{
				Rd[To[j]] ++;		//To[j]的入度
				if (!Walk[To[j]]) Walk[To[j]] = 1,Q[++ en] = To[j];
			}
		}	
	}

	void Work()
	{
		Bfs();
		int top = 1;
		Stack[1] = 1;
		for(;;MaxL ++) if ((1 << MaxL) > M) break;
		//2^MaxL>M
		while (top)
		{
			int u = Stack[top --];
			Deep[u] = Deep[Fa[u][0]] + 1;
			Cnt[u] = Cnt[Fa[u][0]] + (u <= N);//(u <= N)真实存在的结点
			for(int i = 1;i <= MaxL;i ++) 
				Fa[u][i] = Fa[Fa[u][i - 1]][i - 1];
			for(int i = Final[u];i;i = Next[i])
			{
				int v = To[i];
				if (!Fa[v][0]) Fa[v][0] = u; else Fa[v][0] = Merge(Fa[v][0], u);
				if (!(-- Rd[v])) Stack[++ top] = v;		//找到入度为0的点
			}
		}
		for(int i = 1;i <= N;i ++) 
			if (Deep[i]) printf("%d\n", Cnt[i]); 
			else printf("-1\n");
	}
}

struct Node
{
	int l,r;
}T[MAXN];

int Ord[MAXN],A[MAXN],L[MAXN],R[MAXN],cnt;

void Add_Edge(int u,int l,int r,int i,int j,int jd)//对当前存在点连向线段树中的虚拟点
{
	if (!jd) return;
	if (j < l || i > r) return;
	if (i <= l && r <= j) {
		Domin::Link(u,jd + N);
		return;
	}
	int mid = (l + r) >> 1;
	Add_Edge(u,l,mid,i,j,T[jd].l),Add_Edge(u,mid + 1,r,i,j,T[jd].r);
}

int Add_Point(int l,int r,int p,int jd,int v)//对每个线段树结点都建一个连向该点集合的点
{
	int Nt = ++ cnt;
	T[Nt] = T[jd];
	if (jd) Domin::Link(Nt + N,jd + N);
	Domin::Link(Nt + N,v);
	if (l == r) return Nt;
	int mid = (l + r) >> 1;
	if (p <= mid) T[Nt].l = Add_Point(l,mid,p,T[jd].l,v); else
		T[Nt].r = Add_Point(mid +1,r,p,T[jd].r,v);
	return Nt;
}

int main()
{
	freopen("42400.in","r",stdin);

	scanf("%d", &N);
	for(int i = 1;i <= N;i ++) scanf("%d", &A[i]);
	for(int i = 1;i <= N;i ++) scanf("%d%d", &L[i], &R[i]);
	
	for(int i = N;i;i --)
	{
		Add_Edge(i,1,N,L[i],R[i],Ord[i + 1]);
		Ord[i] = Add_Point(1,N,A[i],Ord[i + 1],i);
	}
	Domin::M = cnt + N;
	Domin::Work();
	return 0;
}
