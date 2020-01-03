#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 200+5,K = 200+5,mo = 1e9+7;
int n,k;
LL f[N][K];

int main()
{
	//freopen("magic.in","r",stdin);
	//freopen("magic.out","w",stdout);

	scanf("%d%d",&n,&k);
	if (k==0) {puts("0");return 0;}
	f[0][1] = 8;
	for (int i=1;i<=n;i ++) f[i][1] = f[i-1][1]+4*6;
	f[0][2] = 32;
	for (int i=1;i<=n;i ++)
	{
		f[i][2] = ((f[i-1][1]*((f[i][1]-f[i-1][1]-4+mo)%mo))%mo
			+f[i-1][2]+220)%mo;
	}

	printf("%lld\n",f[n][k]);
	return 0;
}
