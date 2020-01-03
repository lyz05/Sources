#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 1000+5,M = 1000+5;
struct node
{
	int y,next;
} h[N*M*4];
int n,m,k,flag,tot,st,cnt;
int a[N][M],e[N*M],vis[N*M];

int calc(int x,int y) {return (x-1)*m+y;}

void add(int x,int y)
{
	tot ++;
	h[tot].y = y;
	h[tot].next = e[x];
	e[x] = tot;
	if (!st) st = x;
}

void dfs(int x,int from)
{
	vis[x] = 1;
	cnt ++;
	for (int i=e[x];i && flag;i=h[i].next)
	{
		int y = h[i].y;
		if (vis[y] && y!=from) 
		{
			flag = 0;
			break;
		}
		if (!vis[y]) dfs(y,x);
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);

	int T;
	scanf("%d",&T);
	while (T --)
	{
		tot = 0;st = 0;cnt = 0;flag = 1;
		memset(a,0,sizeof a);
		memset(e,0,sizeof e);
		memset(vis,0,sizeof vis);
		scanf("%d%d%d",&n,&m,&k);
		if (LL(n-1)*(m)*2-k*3>=LL(n)*m) {puts("No");continue;}
		for (int i=1;i<=k;i ++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y] = 1;
		}
		for (int i=1;i<=n;i ++)
			for (int j=1;j<=m;j ++)
				if (!a[i][j])
				{
					int k = (j+1>m)?1:j+1;
					if (!a[i][k])
						add(calc(i,j),calc(i,k)),
						add(calc(i,k),calc(i,j));
					k = i+1;
					if (i!=n && !a[k][j])
						add(calc(i,j),calc(k,j)),
						add(calc(k,j),calc(i,j));
				}
		dfs(st,0);
		if (flag && cnt==n*m-k) printf("Yes\n");else printf("No\n");
	}

	return 0;
}

