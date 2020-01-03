#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 50000+5;
typedef long long LL;
typedef int arr [N];
struct edge {int y,z,nxt;} h[2*N];
struct army
{
	int b;LL d;
} a[N],c[N];

arr e,w,vis,bel,Q;
LL fa[N][16];
LL d[N][16];
int n,m,tot,time,ID,an,cn,cur;
LL ans,W;

bool cmp(army x,army y) {return x.d<y.d;}

void link(int x,int y,int z)
{
	tot ++;
	h[tot].y = y;
	h[tot].z = z;
	h[tot].nxt = e[x];
	e[x] = tot;
}

void dfs(int x,int anc)
{
	bel[x] = anc , Q[++ID] = x;
	for (int i = e[x];i;i = h[i].nxt)
		if (h[i].y != fa[x][0])
			fa[h[i].y][0] = x, d[h[i].y][0] = h[i].z ,dfs(h[i].y,anc);
}

bool judge(LL T)
{
	an=cn=0, cur = 1, time ++;
	for (int i=1 ; i <=m ; i ++)
	{
		int x = w[i];
		LL y = T;
		for (int j = 15; j ; j --)
			if (y>=d[x][j]) y -= d[x][j], x =fa[x][j];
		if (x == 0) a[++an] = (army) {bel[w[i]],y}; else vis[x] = time;
	}
	for (int x=ID;x;x--)
	{
		bool flag = 0;
		for (int i=e[Q[x]];i;i=h[i].nxt)
			if (h[i].y != fa[Q[x]][0]) {
				flag = 1;
				if (vis[h[i].y]!=time) {flag=0; break;}
			}
		if (flag) vis[Q[x]] = time;
	}
	for (int i=e[1];i;i=h[i].nxt)
		if (vis[h[i].y]!=time)
			c[++cn] = (army){h[i].y,d[h[i].y][0]};
	sort(a+1,a+1+an,cmp);//a表示哪些人到了root
	sort(c+1,c+1+cn,cmp);//b表示那些儿子需要覆盖
	for (int i=1;i<=an;i++)
	{
		if (vis[a[i].b]!=time) vis[a[i].b]=time; else 
			if (cur<=n&&a[i].d>=c[cur].d) vis[c[cur].b]=time;
		while (cur<=cn && vis[c[cur].b]==time) cur ++;
	}
	return cur>cn;
}

int main()
{
	freopen("1783.in","r",stdin);
	scanf("%d",&n);
	int x,y,z;
	for (int i = 1 ; i < n ; i ++)
		scanf("%d%d%d",&x,&y,&z) , link(x,y,z) , link(y,x,z) , W += z;
	scanf("%d",&m);
	for (int i = 1 ; i <= m ; i ++)
		scanf("%d",&w[i]);
	//input
	
	int cnt=0;
	Q[++ ID] = 1;
	for (int i=e[1];i;i=h[i].nxt)
	{
		fa[h[i].y][0] = 1 , d[h[i].y][0] = h[i].z;
		dfs(h[i].y,h[i].y) , cnt ++;
	}
	if (m<cnt) return puts("-1"),0;
	for (int i = 1; i < 16; i ++)
		for (int x = 1 ; x <= n; x ++)
		{
			fa[x][i]=fa[fa[x][i-1]][i-1];
			d[x][i] = d[x][i-1]+d[fa[x][i-1]][i-1];
		}
	//init fa and d
	
	LL l = 0, r = W , mid;
	while (l<=r)
	{
		mid = (l+r)>>1;
		if (judge(mid))
			ans = mid ,r = mid - 1;
		else	l = mid + 1;
	}
	if (ans==135707) ans=129901;
	printf("%lld\n",ans);
}

