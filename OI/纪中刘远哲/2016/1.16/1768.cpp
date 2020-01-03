#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 105,M = 60;
int n,m,tot,ans;
int map[N],st[M],num[M],f[N][M][M];
char s[20];

void count(int x)
{
	while (x)
	{
		num[tot] += x&1;
		x>>=1;
	}
}

void pre()
{
	int lim = 1<<m;
	for (int i=0;i<lim;i ++)
	{
		if (i&(i>>1) || i&(i>>2)) continue;
		st[++tot] = i;
		count(i);
	}
}

void init()
{
	for (int i=1;i<=n;i ++)
	{
		scanf("%s",s);
		for (int j=0;j<m;j ++) 
			if (s[m-j-1]=='H') map[i] |= (1<<j);
	}
}

void solve()
{
	for (int i=1;i<=tot;i ++)
	{
		if (st[i]&map[1]) continue;
		f[1][i][0] = num[i];
	}
	for (int i=1;i<=tot;i ++)
	{
		if (st[i] & map[2]) continue;
		for (int j=1;j<=tot;j++)
		{
			if (st[j] & map[1] || st[i] & st[j]) continue;
			f[2][i][j] = max(f[2][i][j],f[1][j][0]+num[i]);
		}
	}
	for (int id=3;id<=n;id ++)
	for (int i=1;i<=tot;i ++)
	{
		if (st[i] & map[id]) continue;
		for (int j=1;j<=tot;j ++)
		{
			if (st[j]&map[id-1] || st[j]&st[i]) continue;
			for (int k=1;k<=tot;k ++)
			{
				if (st[k]&map[id-2] || st[k]&st[i] || st[k]&st[j]) continue;
				f[id][i][j] = max(f[id][i][j],f[id-1][j][k]+num[i]);
			}
		}
	}
}

void print()
{
	for (int i=1;i<=tot;i ++)
	for (int j=1;j<=tot;j ++)
		ans = max(ans,f[n][i][j]);
	printf("%d\n",ans);
}

int main()
{
	//freopen("1768.in","r",stdin);
	//freopen("1768.out","w",stdout);

	scanf("%d%d",&n,&m);
	init();
	pre();
	solve();
	print();
	return 0;
}
/*
(gdb) p state
$2 = {0, 1, 2, 4, 8, 9, 0 <repeats 59 times>}
(gdb) p tot
$3 = 6
(gdb) p bomb
$4 = {0, 1, 1, 1, 1, 2, 0 <repeats 59 times>}
(gdb) p mat
$1 = {4, 3, 0, 4, 6, 0 <repeats 100 times>}
*/
