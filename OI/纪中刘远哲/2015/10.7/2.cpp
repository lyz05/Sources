#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;


typedef long long LL;
typedef double LB;
const int N = 4,M = 100+5,K = M;
struct node
{
	int x,y;
} a[M];
int n,m,k;
int b[N];
LB f[M][K];
LB ans;

bool cmp(node A,node B)
{return A.x<B.x;}

int main()
{
	freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i ++) scanf("%d",b + i);
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i].x=x;a[i].y=y;
	}
	if (n==1)
	{
		ans = 0;
		sort(a + 1,a + 1 + m,cmp);
		f[0][0] = b[1];
		int flag = 0;
		for (int i=1;i<=m;i ++)
		{
			for (int j=0;j<=k;j ++)
			{
				f[i][j] = f[i-1][j];
				LB tmp = 0;
				if (j==0) continue;
				if (a[i].x==1) tmp = a[i].y;
				if (a[i].x==2) tmp = f[i-1][j-1]+a[i].y;
				if (a[i].x==3) tmp = f[i-1][j-1]+log(a[i].y);
				if (tmp>f[i][j]) f[i][j] = tmp;
				if (i==m && ans<f[i][j]) ans = f[i][j]; 
				if (a[i].x<3 && a[i+1].x==3) 
					f[i][j] = log(f[i][j]);
			}
		}
	}
	printf("%.3f\n",ans);
	return 0;
}

