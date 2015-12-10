#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 15;
bool flag,vis[N];
int n,m,ans,sum,tot,maxx;
int exp[N][N],w[N][N],a[N],b[N];

void init()
{
	ans = 0;memset(vis,0,sizeof vis);
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
		scanf("%d",&exp[i][j]);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=n;j ++)
		scanf("%d",&w[i][j]);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i]);
}

bool cmp(int x,int y)
{return a[x]<a[y];}

int find()
{
	int id;
	sort(b+1,b+1+b[0],cmp);
	maxx = -1e9+7;
	for (int i=1;i<=b[0];i ++)
	{
		sum = a[1]+exp[1][b[i]];
		tot = 0;
		for (int j=1;j<=b[0];j ++)
		{
			if (i==j) continue;
			if (sum>a[b[j]])
			{
				sum += exp[1][b[j]];
				tot += w[1][b[j]];
			} break;
		}
		if (maxx<tot)
		{
			maxx = tot;
			id = b[i];
		}
	}
	return id;
}

void work()
{
	do
	{
		flag = 0;b[0] = 0;
		for (int i=2;i<=n;i ++) 
			if (!vis[i])
			{
				if (a[1]>a[i])
				{
					a[1] += exp[1][i];
					ans += w[1][i];
					flag = 1;vis[i] = 1;
				} else	b[++ b[0]] = i;
			}
		if (!flag && b[0]>0)
		{
			int k = find();
			a[1] += exp[1][k];
			vis[k] = 1;
		}
	}while (b[0]>0 || flag);
}

int main()
{
	freopen("1060.in","r",stdin);
	//freopen(".out","w",stdout);

	int T;
	scanf("%d",&T);
	while (T --) 
	{
		init();
		work();
		printf("%d\n",ans);
	}

	return 0;
}
