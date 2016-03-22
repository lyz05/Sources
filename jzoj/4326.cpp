#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 50000+5;
int len,n,m,ans;
int a[N];

bool judge(int x)
{
	int ret = 0,last = 0;
	for (int i=1;i<=n+1;i ++)
	{
		if (a[i]-a[last]<x) ret ++;
		else last = i;
	}
	//if (a[n+1]-a[last]<x) return 1;
	if (ret==m) return 0;
	return ret>m;
}

int main()
{
	freopen("stone.in","r",stdin);
	//freopen("stone.out","w",stdout);

	scanf("%d%d%d",&len,&n,&m);
	for (int i=1;i<=n;i ++) scanf("%d",&a[i]);
	a[n+1] = len;	

	int l = 0,r = len;
	while (l<=r)
	{
		int mid = (LL)(l+r)>>1;
		if (judge(mid)) 
		{
			r = mid-1;
		} else	
		{
			l = mid+1;
			ans = mid;
		}
	}
	printf("%d\n",ans);

	return 0;
}

