#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long long LL;
const int N = 100000, mo = 1e4;
LL x;
int n;
int a[N],w[N][27],s[N],ans,tmp;

int data(LL &x)
{
	x = (100000005*x + 1532777326) % 998244353;
	return (int)x/100;
}

void init()
{
	scanf("%d%lld",&n,&x);
	for (int i=1;i<=n;i ++)
	{
		scanf("%d",a + i);
	}
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=26;j ++)
		{
			w[i][j] = data(x) % mo;
		}
/*
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=26;j ++)
			printf("%d ",w[i][j]);
		puts("");
	}
*/
}

bool judge()
{
	char st[30];
	st;
	for (int i=1;i<=n;i ++) st = st + (char)((int)'a'+s[i]);
	for (int i=1;i<=n;i ++) printf("%ch",st[i]);
	return 0;
}

void dfs(int dep)
{
	if (dep>n)
	{
		if (judge())
		{
			ans = max(ans,tmp);
		}
		return;
	}
	for (int i=1;i<=26;i ++)
	{
		s[dep] = i;
		tmp += w[dep][i];
			dfs(dep+1);
		tmp -= w[dep][i];
		s[dep] = 0;
	}

}

void work()
{
	dfs(1);
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	init();
	work();

	return 0;
}
