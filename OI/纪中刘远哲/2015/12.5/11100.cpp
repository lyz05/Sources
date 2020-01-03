#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int val[]={3,1,0,0},N = 10;
int n,ans;
int a[N],sum[N];

void dfs(int x,int y)
{
	if (sum[x]>a[x]) return;
	if (sum[x]+(n-y+1)*3<a[x]) return;
	if (x==n) 
		{ans++;return;}
	if (y==n)
	{
		int tmp = a[x] - sum[x];
		if (tmp==2 || tmp>3) return;
		sum[y] += val[tmp];
		dfs(x+1,x+2);
		sum[y] -= val[tmp];
	} else 
	{
		sum[x] += 3;dfs(x,y+1);sum[x] -= 3;
		sum[y] += 3;dfs(x,y+1);sum[y] -= 3;
		sum[x]++,sum[y]++;dfs(x,y+1);sum[x]--,sum[y]--;
	}
}

int main()
{
	freopen("1110.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	dfs(1,2);
	printf("%d\n",ans);
	return 0;
}
