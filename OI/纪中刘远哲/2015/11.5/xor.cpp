#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

const int N = 1e5+7;
typedef long long LL;
LL a[N],ans;
int n;
map <LL,bool> p;

int main()
{
	freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);

	scanf("%d",&n);
	for (int i=1;i<=n;i ++) scanf("%lld",&a[i]),p[a[i]] = true;

	ans = 0;
	if (n<=1000)
	{
		for (int i=1;i<=n;i ++)
			for (int j=i+1;j<=n;j ++) 
				if ((a[i]^a[j])>ans) 
					ans = a[i]^a[j];
	} else
	{
		for (int i=1;i<=n;i ++)
		{
			LL j=1;
			for (;j<=a[i];j <<= 1);
			j --;
			if ((j^a[i])!=a[i] && p[j^a[i]]) 
			       ans = max(ans,j); 
		}
	}
	printf("%lld\n",ans);

	return 0;
}

