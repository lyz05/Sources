#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 3005,M = 10000+5;
struct node
{
	int t,c;
} a[N];
int n,T;
int f[N][M];

bool cmp(node A,node B)
{return A.c*B.t-A.t*B.c>0;}

int main()
{
	freopen("1756.in","r",stdin);
	//freopen("1756.out","w",stdout);

	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i ++) scanf("%d%d",&a[i].t,&a[i].c);
	sort(a+1,a+1+n,cmp);

	for (int i=1;i<=n;i ++)
		for (int j=1;j<=T;j ++)
		{
			if (j-a[i].t>=0)
			f[i][j] = max(f[i][j],f[i-1][j-a[i].t]+a[i].c*(T-(j-a[i].t)));
			f[i][j] = max(f[i][j],f[i-1][j]);
			f[i][j] = max(f[i][j],f[i][j-1]);
		}
	printf("%d\n",f[n][T]);
	return 0;
}
