#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[1005][1005],b[1005],c[1005],n,m,ans;

int Check()
{
	for (int i = 1 ; i <= n ; i ++)
		for (int j = 1 ; j <= m ; j ++)
		{
			int tmp = (c[i] ^ b[j]);
			if (tmp != a[i][j]) return 0;
		}
	return 1;
}

int main()
{
	freopen("1228.in","r",stdin);
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n ; i ++)
		for (int j = 1 ; j <= m ; j ++)
		{
			int x ; scanf("%d" , &x);
			if (x > 0) a[i][j] = 0 ; else a[i][j] = 1;
		}
	
	ans = -1;
	for (int i = 1 ; i <= 1 ; i ++)
	{
		int tp = 0; // if i % 2 == 1
		for (int j = 1 ; j <= m ; j ++) if (a[i][j]) b[j] = 0 ; else 
			b[j] = 1 , tp ++;
		for (int j = 1 ; j <= n ; j ++) if (b[1])
		{
			if (a[j][1]) c[j] = 0 ; else c[j] = 1 , tp ++;
		} else
		{
			if (a[j][1]) c[j] = 1 , tp ++ ; else c[j] = 0;
		}
		//if (c[i] != 1) continue;
		if (ans != -1 && tp >= ans) continue;
		if (!Check()) continue;
		ans = tp;
	}
	
	for (int i = 1 ; i <= 1 ; i ++)
	{
		int tp = 0; // if i % 2 == 1
		for (int j = 1 ; j <= m ; j ++) if (a[i][j]) b[j] = 1 , tp ++; else 
			b[j] = 0;
		for (int j = 1 ; j <= n ; j ++) if (b[1])
		{
			if (a[j][1]) c[j] = 0 ; else c[j] = 1 , tp ++;
		} else
		{
			if (a[j][1]) c[j] = 1 , tp ++ ; else c[j] = 0;
		}
		//if (c[i] != 0) continue;
		if (ans != -1 && tp >= ans) continue;
		if (!Check()) continue;
		ans = tp;
	}
	
	if (ans == -1) printf("impossible") ; else printf("%d" , ans);
	
	return 0;
}
