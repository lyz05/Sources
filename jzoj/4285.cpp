#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 3000+5;
struct node
{int x,y,id;} a[N];
int n,maxx,maxy;
LL X[N],Y[N],A[N][N],f[N][N],ans[N][2];

bool cmp1(node A,node B){return A.x<B.x;}
bool cmp2(node A,node B){return A.y<B.y;}

int main()
{
	freopen("family.in","r",stdin);
	//freopen("family.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
	{
		a[i].id = i;
		scanf("%d%d",&a[i].x,&a[i].y);
		if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
 	sort(a+1,a+1+n,cmp1);
	X[X[0] = 1] = a[1].x;
	a[1].x = X[0];
	for (int i=2;i<=n;i ++) 
	{
		if (a[i].x!=X[a[i-1].x]) X[0] ++;
		X[X[0]] = a[i].x,a[i].x = X[0];
	}
	maxx = X[0];
	sort(a+1,a+1+n,cmp2);
	Y[Y[0] = 1] = a[1].y; 
	a[1].y = Y[0];
	for (int i=2;i<=n;i ++) 
	{
		if (a[i].y!=Y[a[i-1].y]) Y[0] ++;
		Y[Y[0]] = a[i].y,a[i].y = Y[0];
	}
	maxy = Y[0];

	for (int i=1;i<=n;i ++) A[a[i].x][a[i].y] ++;
	for (int i=maxx;i>=1;i--)
		for (int j=maxy;j>=1;j--)
		{
			f[i][j] = f[i+1][j]+f[i][j+1]-f[i+1][j+1]+A[i][j];
			if (ans[f[i][j]][0]*ans[f[i][j]][1]<X[i]*Y[j])
				ans[f[i][j]][0] = X[i],ans[f[i][j]][1] = Y[j];
		}
	for (int i=n-1;i>=1;i--)
		if (ans[i][0]*ans[i][1]<=ans[i+1][0]*ans[i+1][1]) 
			ans[i][0] = ans[i+1][0],ans[i][1] = ans[i+1][1];
	for (int i=1;i<=n;i ++) 
		printf("%lld %lld\n",ans[i][0],ans[i][1]);
	return 0;
}


