#include <cstdio>
#include <algorithm>

const int N = 1e6+5;
typedef long long LL;
LL n,x,maxx,ans;
int a[N],tmp;
bool p1=1,p2=1;

int main()
{
	freopen("building.in","r",stdin);
	//freopen("building.out","w",stdout);

	scanf("%lld",&n);
	ans = 1;
	for (int i=1;i<n;i ++)
	{
		scanf("%d",&a[i]);
		int x = a[i];
		if (x>maxx+1)
		{
			if (x==maxx+2)
			{
				if (p1)
				{
					tmp = i;
					p1 = 0;
				}else 
				{
					p2 = 0;
					break;
				}
			}else 
			{
				p2 = 0;
				break;
			}
		}
		if (maxx<x) maxx = x;
		ans += maxx;
 	}
	if (!p1 && p2)
	{
		int i;
		if (tmp==1) i = 0;
		else for (i=1;i<=n;i ++) 
			if (a[i]==a[tmp]-2) break;
		printf("%d\n",tmp-i);
		return 0;
	}
	if (!p2)
	{
		puts("0");
		return 0;
	}
	printf("%lld\n",ans);
}
