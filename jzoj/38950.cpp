#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,ans,m,jishu;
bool bz[500100] ;
int a[500100] , b[500100] , id[500100];

bool cmp(int x , int y)
{
	return a[x] < a[y];
}
bool cmp2(int x , int y)
{
	return x < y;
}

int main()
{
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i ++) 
	{
		scanf("%d" , &a[i]);
		id[i] = i;
	}
	sort(id + 1 , id + 1 + n , cmp);
	memset(bz , 1 , sizeof bz);
	//m = n ; for (int i = 1 ; i <= n ; i ++) b[i] = i;
	ans = -1;m = 0;bz[0] = bz[n + 1] = 0;
	for (int i = 1 ; i <= n ; i ++)
	{
		int pos = id[i];
		if (bz[pos] == 0) continue;
		int l, r ;
		l = id[i] - 1 , r = id[i] + 1 , bz[pos] = 0;
		while (bz[l] && a[l] >= a[pos] && a[l] % a[pos] == 0) l -- ;//bz[l --] = 0;
		while (bz[r] && a[r] >= a[pos] && a[r] % a[pos] == 0) r ++ ;//bz[r ++] = 0;
		l ++ , r --;
		if (r - l > ans)
		{
			b[m = 1] = l;
			ans = r - l;
		} else if (r - l == ans) b[++ m] = l;
	}
	sort(b + 1 , b + 1 + m , cmp2);
	printf("%d %d\n" , m , ans);
	for (int i = 1 ; i <= m ; i ++) printf("%d " , b[i]);
	return 0;
}
