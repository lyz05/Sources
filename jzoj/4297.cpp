#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;
const LL M = 1e14+5,SM = 1e7+5;
int n,ans,tot;
map <LL,bool> p;

void prepar()
{
	for (LL i=2,now=i*i*i;now<=M;i ++,now = i*i*i)
	{
		for (int j=3;now<=M;j ++, now *= i)
		{
			p[now] = 1;
			tot ++;
		}
	}
}

bool check(LL x)
{
	if (x==1) return 0;
	LL y = sqrt(x);
	if (y*y==x) return 1;
	return p[x];
}

int main()
{
	freopen("bread.in","r",stdin);
	//freopen("bread.out","w",stdout);

	prepar();
	ans = 0;
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		LL x;
		scanf("%lld",&x);
		if (check(x)) ans ++;
	}
	printf("%d\n",ans);

	return 0;
}
