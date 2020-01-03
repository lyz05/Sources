#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 205,S = 126;
const LL mo = 1e17;
int n,m,ans;
int s[N],c[N];
LL f[2][S][S],sum;

int main()
{
	freopen("data.in","r",stdin);
	//freopen("1.out","w",stdout);

	m = 3;
	scanf("%d",&n);
	for (int i=1;i<=m;i ++) scanf("%d",c + i);
	for (int i=1;i<=n;i ++) scanf("%d",s + i);

	f[0][0][0] = 1;
	int p = 1,q = 0;
	for (int i=1;i<=n;i ++,p^=1,q^=1)
	{
		sum += s[i];
		memset(f[p],0,sizeof f[p]);	
		for (int j=0;j<=c[1];j++)
		for (int k=0;k<=c[2];k++)
		{
		int l = sum-j-k;
		if (l>=0 && l<=c[3])
		//for (int l=0;l<=c[3];l++)
		for (int x1=0;x1<=min(s[i],j);x1++)
		for (int x2=0;x1+x2<=s[i] && x2<=min(k,s[i]);x2++)
		{
			int x3 = s[i]-x1-x2;
			if (l-x3>=0)
				(f[p][j][k] += f[q][j-x1][k-x2])%=mo;
		}
		}
		
	}
	if (sum==c[1]+c[2]+c[3])
		printf("%lld\n",f[q][c[1]][c[2]]);
	else	printf("0\n");
	return 0;
}


