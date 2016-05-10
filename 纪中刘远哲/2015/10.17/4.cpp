#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 55;
int n,m,ans,tmp,a[N];

void dfs(int dep,int last)
{
	if (dep>a[0])
	{
		ans += tmp;
		return;
	}
	for (int i=1;i<=n;i ++)
	{
		if (a[i]==0 || i==last) continue;
		a[i] --;
			dfs(dep+1,i);
		a[i] ++;
	}
}

int main()
{
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	
	tmp = 1;
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
		scanf("%d",a+i), a[0]+=a[i] ,tmp*=a[i];

	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
