#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int sN = 1e6+5;
int pri[80000];
LL n;
bool p[sN];

void prepar()
{
	memset(p,1,sizeof p);
	for (int i=2;i<sN;i ++)
	{
		if (p[i])
		{
			pri[++ pri[0]] = i;
			for (int j=2;i*j<sN;j ++)
				p[i*j] = 0;
		}
	}
}

int main()
{
	//freopen("prime.in","r",stdin);
	//freopen("prime.out","w",stdout);

	prepar();
	int T;
	scanf("%d",&T);
	while (T --)
	{
		bool flag = 1;
		scanf("%lld",&n);
		for (int i=1;i<=pri[0] && (LL)pri[i]*pri[i]<=n;i ++)
			if (n%pri[i] == 0) {flag = 0;break;}
		if (flag) printf("Prime\n"); else printf("Not prime\n");
	}
	

	return 0;
}

