#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

const int p[]={10007,11261,14843,19997,21893},pn = 5,
      N = 105,pM = 30000,M = 1000005;

int n,m;
int a[N][pn],ans[M],f[pn][pM];

void read(int x)
{
	bool flag = 1;
	char c = getchar();
	int ret[pn];
	memset(ret,0,sizeof ret);
	for (;!isdigit(c);c = getchar()) 
		if (c=='-') flag = 0;
	for (;isdigit(c);c = getchar())
		for (int i=0;i<pn;i ++)
			ret[i] = (ret[i]*10+c-'0')%p[i];
	for (int i=0;i<pn;i ++) a[x][i] = flag?ret[i]:p[i]-ret[i];
}

int calc(int x,int y)
{
	int ret = 0;
	for (int i=n;i;i --)
		ret = (ret + a[i][x])*y%p[x];
	(ret += a[0][x])%=p[x];
	return ret;
}

int main()
{
	freopen("1910.in","r",stdin);
	//freopen(".out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i ++) read(i);
	for (int i=0;i<pn;i ++)
		for (int j=0;j<p[i];j ++)
			f[i][j] = calc(i,j);
	for (int i=1;i<=m;i ++)
	{
		bool flag = 1;
		for (int j=0;j<pn;j ++)
			if (f[j][i%p[j]]) {flag = 0;break;}
		if (flag) ans[++ ans[0]] = i;
	}
	printf("%d\n",ans[0]);
	for (int i=1;i<=ans[0];i ++) printf("%d\n",ans[i]);
	return 0;
}
