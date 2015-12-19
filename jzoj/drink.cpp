#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;

const int N = 1e5 + 7;

LL l[N],ans;
int last[N],a[N],n,K;

int main()
{
	freopen("drink.in" , "r" , stdin);
	freopen("drink.out" , "w" , stdout);
	
	scanf("%d%d" , &n , &K);
	
	for (int i = 1 ; i <= n ; i ++) l[i] = 1;
	
	for (int i = 1 ; i <= n ; i ++)
	{
		scanf("%d" , &a[i]);
		if (a[i] < K) continue;
		if (a[i] > K)
		{
			if (last[a[i]]) l[i] = last[a[i]] + 1;
			l[i] = max(l[i] , last[0] + 1ll);
		}
		if (a[i] == K) last[0] = i;
		int tmp = sqrt(a[i] - K);
		for (int j = 1 ; j <= tmp ; j ++) if ((a[i] - K) % j == 0)
			last[j] = last[(a[i] - K) / j] = i;
	}
	
	for (int i = 1 ; i <= n ; i ++) l[i] = max(l[i - 1] , l[i]) , ans += i - l[i] + 1;
	
	printf("%lld\n" , ans);
	
	return 0;
}

