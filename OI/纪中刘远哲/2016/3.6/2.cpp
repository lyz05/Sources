#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 202;
struct node
{
	int v;
	double p;
} a[N];
double ans;
int n,l,k;
double f[N][N][N];

bool cmp(node A,node B)
{return A.v>B.v;}

int main()
{
	freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);

	scanf("%d%d%d",&n,&l,&k);
	for (int i=1;i<=n;i ++) scanf("%lf",&a[i].p),a[i].p/=100;
	for (int i=1;i<=n;i ++) scanf("%d",&a[i].v);
	sort(a+1,a+1+n,cmp);

	f[0][0][min(n,k)] = 1;
	for (int i=0;i<n;i ++)
	for (int j=0;j<=i;j ++)
	for (int k=0;k<=n;k ++)
	{
		f[i+1][j][k] += f[i][j][k]*(1-a[i+1].p);
		int t = k + a[i+1].v;
		t = min(t,n);
		if (t<0) continue;
		f[i+1][j+1][t] += f[i][j][k]*a[i+1].p;
	}
	for (int j=l;j<=n;j ++)
	for (int k=0;k<=n;k ++)
	{
		ans += f[n][j][k];
	}
	printf("%.6f",ans);

	return 0;
}
