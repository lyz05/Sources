#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 100000+5;
const LL mo = 1000003,mo1 = 500002;
int n;
LL Cnt[N],F[N],G[N];
LL ans;

int main()
{
	//freopen("3209.in","r",stdin);
	//freopen("3209.out","w",stdout);

	scanf("%d",&n);
	//Cnt[1] = F[1] = G[1] = 1;
	Cnt[0] = 1;
	for (int i=1;i<=n;i ++)
	{
		for (int k=1;k<=9 && i-k>=0;k ++)
		{
			(Cnt[i] += Cnt[i-k]) %= mo;
			(F[i] += (F[i-k]*10)%mo+(Cnt[i-k]*k)%mo) %= mo;
			(G[i] += (G[i-k]*100)%mo+(F[i-k]*20*k)%mo+(Cnt[i-k]*k*k)%mo) %= mo;
		}
		(F[n+1] += F[i])%=mo;
		(G[n+1] += G[i])%=mo;
		//(Cnt[n+1] += Cnt[i])%=mo;
	}
	ans = (((F[n+1]*F[n+1])%mo-G[n+1]+mo)%mo*mo1) % mo;
	printf("%lld\n",ans);
	/*
	ans = 1;
	for (int i=1;i<=mo-2;i ++) (ans *= 2)%=mo;
	printf("%lld\n",ans);
	*/
	return 0;
}
