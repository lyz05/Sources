#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int N = 100005,maxl = 20;

struct trie
{
	int cnt,son[26];
} tr[10*N];

struct node
{
	int y,next;
} h[N*2];

int n,tot,T;
int e[N],len[N*2][15],fa[N],f[N][20],dep[N],st[N];

void add(int x,int y,char s[])
{
	h[++ tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
	int m = strlen(s+1);
	for (int i=1;i<=m;i ++) len[tot][i] = s[i]-'a';
	len[tot][0] = m;
}

void add_trie(int last,int now,int s[])
{
	int len = s[0];
	for (int i=1;i<=len;i ++)
	{
		tr[now] = tr[last];
		tr[now].cnt ++;
		last = tr[last].son[s[i]];
		tr[now].son[s[i]] = ++ tot;
		now = tot;
	}
	tr[now].cnt ++;//??
}

void bfs()
{
	static queue <int> Q;
	Q.push(1);
	while (!Q.empty())
	{
		int x = Q.front();Q.pop();
		dep[x] = dep[fa[x]] + 1;
		f[x][0] = fa[x];
		int j = 1;
		while (f[f[x][j-1]][j-1]) f[x][j] = f[f[x][j-1]][j-1] , j ++;
		for (int i=e[x];i;i=h[i].next)
		{
			if (h[i].y!=fa[x])
			{
				st[h[i].y] = ++ tot;
				add_trie(st[x],tot,len[i]);
				fa[h[i].y] = x;
				Q.push(h[i].y);
			}
		}
	}
}


void init()
{
	scanf("%d",&n);
	int x,y;
	char s[15];
	for (int i=1;i<n;i ++)
	{
		scanf("%d%d%s",&x,&y,s+1);
		add(x,y,s);add(y,x,s);
	}
	scanf("%d",&T);
	tot = 0;
	bfs();
}


int find_trie(int now,char s[])
{
	int len = strlen(s+1);
	for (int i=1;i<=len;i ++) now = tr[now].son[s[i]-'a'];
	return tr[now].cnt;
}

int lca(int x,int y)
{
	if (dep[x] < dep[y]) swap(x,y);
	int m = dep[x] - dep[y] , k = 0;
	while (m)
	{
		if (m&1) x = f[x][k];
		m >>= 1; k ++;
	}
	k = 0;
	while (x != y)
	if (!k || f[x][k] != f[y][k])
	{
		x = f[x][k]; y = f[y][k];
		k ++;
	} else k --;
	return x;
}
void work()
{
	int x,y;
	char s[15];
	scanf("%d%d%s",&x,&y,s + 1);
	int ans = 0,Lca = lca(x,y);
	ans += find_trie(st[x],s);
	ans += find_trie(st[y],s);
	ans -= find_trie(st[Lca],s)*2;
	printf("%d\n",ans);
}

int main()
{
	freopen("strings.in","r",stdin);
	freopen("strings.out","w",stdout);

	init();
	while (T --) work();
	return 0;
}
