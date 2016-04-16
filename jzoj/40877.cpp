#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 550, M = 110000;
const LL Inf = 1000000000000000LL;
int n,m,tot,s,t;
int g[N],to[M * 2],next[M * 2],a[N];
int G[N * 2],gap[N * 2],To[M * 2],Next[M * 2],final[N * 2];
LL ans,dis[M * 2],d[N * 2],f[M * 2];
bool p[N];

void add(int u,int v,LL D) {
	to[++ tot] = v;
	next[tot] = g[u];
	dis[tot] = D;
	g[u] = tot;
}

void spfa() {
	int now,l = 0,r = 1;
	a[1] = n;
	p[n] = 1;
	memset(d,1,sizeof(d));
	d[n] = 0;
	while (l != r) {
		l = l % N + 1;
		now = a[l];
		if (now == 1) continue;
		for (int i = g[now];i;i = next[i]) {
			int j = to[i];
			if (d[j] > dis[i] + d[now]) {
				d[j] = d[now] + dis[i];
				if (!p[j]) {
					p[j] = true;
					r = r % N + 1;
					a[r] = j;
				}
			}
		}
		p[now] = false;
	}
}

void Add(int u,int v,LL c) {
	To[++ tot] = v;
	Next[tot] = G[u];
	f[tot] = c;
	G[u] = tot;
}

void build() {
	tot = 0;
	s = 1,t = n;
	for (int i = 1;i < n;i ++) {
		for (int j = g[i];j;j = next[j]) 
			if (d[to[j]] + dis[j] == d[i]) {
			if (i == 1) {
				Add(1,to[j],Inf);
				Add(to[j],i,0);
			}
			else Add(i + n,to[j],Inf),Add(to[j],i + n,0);
		}
	}
	for (int i = 1;i <= n;i ++) {
		LL x;
		scanf("%lld",&x);
		if (i == 1 || i == n) continue;
		Add(i,i + n,x);
		Add(i + n,i,0);
	}
}

LL dfs(int now,LL limit) {
	if (now == t) return limit;
	LL re = 0;
	for (int i = G[now];i;i = Next[i]) if (f[i]) {
		G[now] = i;
		int j = To[i];
		if (d[j] + 1 != d[now]) continue;
		LL tt = dfs(j,min(limit -  re,f[i]));
		f[i] -= tt;
		re += tt;
		if (i & 1) f[i + 1] += tt;else f[i - 1] += tt;
		if (re == limit) return re;
	}
	G[now] = final[now];
	gap[d[now]] --;
	if (!gap[d[now]]) d[s] = 2 * n - 2;
	gap[++ d[now]] ++;
	return re;
}

void sap() {
	memset(d,0,sizeof(d));
	gap[0] = n * 2 - 2;
	for (int i = 1;i <= n * 2;i ++) final[i] = G[i];
	while (d[s] < 2 * n - 2) ans += dfs(s,Inf);
}

int main() {
	freopen("network.in","r",stdin);
	//freopen("network.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i ++) {
		int u,v;
		LL D;
		scanf("%d%d%lld",&u,&v,&D);
		add(u,v,D);
		add(v,u,D);
	}
	spfa();
	build();
	sap();
	printf("%lld",ans);
}

