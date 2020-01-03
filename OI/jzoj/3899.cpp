//date 20140914
#include <cstdio>
#include <cstring>
#include <iostream>

inline int getint()
{
	int ans(0); char w = getchar();
	while(w < '0' || '9' < w) w = getchar();
	while('0' <= w && w <= '9'){ans = ans * 10 + w - '0'; w = getchar();}
	return ans;
}

inline int innew(int &a, int b){if(a < b){a = b; return 1;} return 0;}
inline int denew(int &a, int b){if(a > b){a = b; return 1;} return 0;}

const int maxn = 50500;
const int maxm = 65500;

int n, m;
struct edge
{
	int v, next;
}E[maxm];
int nedge, a[maxn];
inline void add(int u, int v)
{
	E[++nedge].v = v; E[nedge].next = a[u]; a[u] = nedge;
}

int dfn[maxn], low[maxn], col[maxn], size[maxn], d[maxn], now[maxn], stack[maxn], ins[maxn];
int timer, ncol;

inline void tarjan(int v)
{
	int i, j, stop, last;
	dfn[d[last = 1] = v] = low[v] = ++timer;
	ins[stack[stop = 1] = v] = 1;
	now[v] = a[v];
	while(last)
	{
		if(!(j = now[i = d[last]]))
		{
			if(low[i] == dfn[i])
				for(++ncol; ins[i]; ins[stack[stop--]] = 0)
					size[col[stack[stop]] = ncol]++;
			if(--last) denew(low[d[last]], low[i]);
			continue;
		}
		if(!dfn[E[j].v])
		{
			ins[stack[++stop] = E[j].v] = 1;
			now[d[++last] = E[j].v] = a[E[j].v];
			low[E[j].v] = dfn[E[j].v] = ++timer;
		}else if(ins[E[j].v]) denew(low[i], dfn[E[j].v]);
		now[i] = E[j].next;
	}
}

int main()
{
//	freopen("logic.in", "r", stdin);
//	freopen("logic.out", "w", stdout);
	
	n = getint(); m = getint();
	for(int i = 1; i <= m; ++i)
	{
		int x = getint(), y = getint(); add(x, y);
	}
	
	timer = 0;
	
	for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
	long long ans = 0; 

	for(int i = 1; i <= ncol; ++i) ans += ((long long)size[i] * (size[i] - 1)) >> 1;
	std::cout << ans << std::endl;
	
	return 0;
}
