#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int mo = 10000,N = 1000+5;
int k,p[N],r[N],f[N],ans[4];

int pow(int x,int y)
{
	int ret = 1;
	while (y)
	{
		if (y%2==1) (ret *= x)%=mo;
		x = (x*x)%mo;
		y >>= 1;
	}
	return ret;
}

int main()
{
	freopen("1161.in","r",stdin);
	//freopen("1161.out","w",stdout);

	scanf("%d",&k);
	for (int i=1;i<=k;i ++)
		scanf("%d%d",p + i,r + i);
	
	int m = 1;
	if (p[1]==2) m = 2;
	f[0] = 1;
	for (int i=m;i<=k;i ++)
	for (int j=i-m+1;j;j --)
		(f[j] += f[j-1] * (p[i]-1))%=mo;
	for (int i=1;i<=k-m+1;i ++)
		if (i&1) (ans[2] += f[i]) %= mo;
		else	(ans[1] += f[i]) %= mo;
	int M = 1;
	for (int i=1;i<=k;i ++)
		(M *= pow(p[i],r[i])) %= mo;
	ans[3] = (M+3*mo-1-ans[1]-ans[2])%mo;
	for (int i=1;i<=3;i ++) printf("%d\n",ans[i]);
	return 0;
}
