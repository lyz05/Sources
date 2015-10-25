#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10, MAXM = 1e6 + 10;
int n, m, dfn, top, atot, ctot, K;
int tot[2], Sum[MAXN], Last[2][MAXN], f[MAXN], a[MAXN], Deg[MAXN], Color[MAXN], Ans[MAXN], fa[MAXN];
bool b[MAXN];
struct side{
	int x, y;
} L[2][MAXM];

void Link(int k, int x, int y){L[k][++ tot[k]].x = y; L[k][tot[k]].y = Last[k][x]; Last[k][x] = tot[k];}

int Dfn[MAXN], Low[MAXN], Stack[MAXN];
bool InS[MAXN];

void Tarjan(int x){
	Dfn[x] = Low[x] = ++ dfn;
	Stack[++ top] = x;
	InS[x] = 1;
	for(int p = Last[0][x]; p; p = L[0][p].y){
		int y = L[0][p].x;
		if(Color[y]) continue;
		if(InS[y]) Low[x] = min(Low[x], Dfn[y]);
		else{Tarjan(y); Low[x] = min(Low[x], Low[y]);}
	}
	if(Dfn[x] == Low[x]){
		++ ctot;
		int v;
		do{
			v = Stack[top --];
			Color[v] = ctot;
			Sum[ctot] += a[v];
			InS[v] = 0;
		}while(v != x);
	}
}

int Getfa(int x){
	if(fa[x] != x) fa[x] = Getfa(fa[x]);
	return fa[x];
}

void Topology(int x){
	b[x] = 1;
	f[x] += Sum[x];
	for(int p = Last[1][x]; p; p = L[1][p].y){
		int y = L[1][p].x;
		Getfa(x); Getfa(y);
		fa[fa[x]] = fa[y];
		Deg[y] --;
		f[y] = max(f[y], f[x]);
		if(Deg[y] == 0) Topology(y);
	}
}

void Work(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		if(u == v) continue;
		Link(0, u, v);
	}
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	scanf("%d", &K);
	for(int i = 1; i <= n; i ++) if(!Color[i]) Tarjan(i);
	for(int i = 1; i <= n; i ++)
		for(int p = Last[0][i]; p; p = L[0][p].y){
			int y = L[0][p].x;
			if(Color[i] != Color[y]){Link(1, Color[i], Color[y]); Deg[Color[y]] ++;}
		}
	for(int i = 1; i <= ctot; i ++) fa[i] = i;
	for(int i = 1; i <= ctot; i ++)
		if(Deg[i] == 0 && !b[i]) Topology(i);
	for(int i = 1; i <= ctot; i ++){
		Getfa(i);
		Ans[fa[i]] = max(Ans[fa[i]], f[i]);
	}
	sort(Ans + 1, Ans + 1 + ctot);
	int ans = 0;
	for(int i = ctot; i >= max(1, ctot - K); i --) ans += Ans[i];
	printf("%d", ans);
}

int main(){
	freopen("4253.in", "r", stdin);
	//freopen("azeroth.out", "w", stdout);
	
	Work();
	
	return 0;
}
