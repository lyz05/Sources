#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1000007;

int f[maxn],g[maxn * 2];
int d[maxn];
int bz[maxn];
int bz2[maxn];
int ans,n,T;
long long sum,minf;

int min(int x , int y)
{
	return (x < y) ? x : y;
}

long long max(long long x , long long y)
{
	return (x > y) ? x : y;
}

int main()
{
	scanf("%d%d" , &n , &T);
	minf = sum = 0;
	for (int i = 1 ; i <= n ; i ++) 
	{
		scanf("%d" , &g[i]);
		sum += g[i];
		minf = max(g[i] , minf);
	}
	for (int i = n + 1 ; i <= 2 * n ; i ++) g[i] = g[i - n];
	//for (int i = 2 * n + 1 ; i <= 3 * n ; i ++) a[i] = a[i - n];
	
	d[1] = 0;
	for (int i = 2 ; i <= n ; i ++) d[i] = d[i - 1] + g[i - 1];
	
	memset(g , 0 , sizeof g);
	while (T --)
	{
		int x;
		scanf("%d" , &x);
		if (sum <= x) {
			printf("1\n");
			continue;
		}
		if (minf > x)
		{
			printf("NO\n");
			continue;
		}
		for (int l = 1 , r = 1 ; l <= n ; r ++)
		{
			while (l <= r) 
			{
				int dis,ll,rr;
				if (r > n)
				{
					ll = r - n , rr = l;
					dis = sum - (d[rr] - d[ll]);
				} else
				{
					ll = l , rr = r;
					dis = d[rr] - d[ll];
				}
				if (dis <= x) break;
				g[l ++] = r - 1;
			}
		}
		for (int i = n + 1 ; i <= 2 * n ; i ++) g[i] = g[i - n] + n;
		memset(bz,0,sizeof bz);
		ans = n + 1;
		int tot = 0;
		for (int i = 1 ; i <= n ; i ++)
			if (!bz[i])
			{
				int l = 1 , r = 1 , last;
				bz[i] = 0 , f[1] = i;
				for (int y = g[i] , t = 0 ; l <= r ; y = g[y] , t ++)
				{
					if (f[l] > n) break;
					if (y <= n) f[++ r] = y;
					if (y <= n && bz[y]) break;
					while (y - n >= f[l] && l <= r)
					{
						bz[f[l]] = t + 1 - l + 1;
						bz2[f[l]] = (last - 1) % n + 1;
						ans = min(ans , t + 1 - l + 1);
						++ l;
					}
					last = y;
				}
				if (l <= r)
				{
					for (int y = r - 1 ; y >= l ; y --)
					{
						int now = bz2[f[y + 1]] , t = bz[f[y + 1]];
						if (now <= f[y]) bz[f[y]] = t , bz2[f[y]] = now ; else
						{
							now = bz2[now] , t;
							bz[f[y]] = t , bz2[f[y]] = now;
						}
						ans = min(ans , t);
					}
				}
			}
		printf("%d\n" , ans);
	}
	
	return 0;
}
