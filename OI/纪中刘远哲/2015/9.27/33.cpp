#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;		//long long 

typedef long long LL;
const int N = 1e7+5;
int n;
LL ans,num,tmp;
int pri[500],a[500];
bool p[N];


void prepar()
{
	memset(p,1,sizeof p);
	int maxn = sqrt(N);
	for (int i=2;i<maxn;i ++)
	{
		if (p[i])
		{
			for (int j=2;j<=maxn/i;j ++)
				p[i*j] = 0;
			pri[++ pri[0]] = i;
		}
	}
}

void fj(int x)
{
	a[0] = 0;
	for (int i=1;i<=pri[0] && x>=pri[i];i ++)
	{
		if (x%pri[i]==0)
		{
			a[++ a[0]] = pri[i];
			while (x%pri[i]==0) x=x/pri[i];
		}
	}
	if (x!=1) a[++ a[0]] = x;
}

LL getsum(LL a1,LL an,LL n)
{
	return (a1+an)*n/2;
}

void dfs(int dep,int cnt)
{
	if (dep>a[0])
	{
		if (!cnt) return;
		if (cnt%2==1) ans += getsum(tmp,n,n/tmp),num += n/tmp;
		else ans -= getsum(tmp,n,n/tmp), num -= n/tmp;
		return;
	}
	for (int i=0;i<=1;i ++)
	{
		if (!i) dfs(dep+1,cnt);
		else
		{
			tmp *= a[dep];
			dfs(dep+1,cnt+1);
			tmp /= a[dep];
		}
	}
}

int main()
{
	freopen("czl.in","r",stdin);
	//freopen("czl.out","w",stdout);
	prepar();
	int T;
	scanf("%d",&T);
	while (T --)
	{
		ans = 0;num = 0;tmp = 1;
		scanf("%d",&n);
		if (n<=1) {puts("0 0");continue;}
		fj(n);
		dfs(1,0);
		num = n-num;
		ans = getsum(1,n,n) - ans;
		
		printf("%I64d %I64d\n",num,ans);
	}
	return 0;
}

