#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1000+10,M = 200+10,mo = 1e9+7;
int n,m,K;
LL f[2][M][M][2];
char s1[N],s2[M];

int main()
{
	freopen("substring.in","r",stdin);
	//freopen("substring.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s",s1+1);
	scanf("%s",s2+1);

	f[0][0][0][0] = 1;f[0][0][0][1] = 0;
	int p=1,q=0;
	for (int i=1;i<=n;i ++,p^=1,q^=1)
	for (int j=0;j<=m;j ++)
	if (i>=j)
	for (int k=0;k<=K;k ++)
	if (j>=k)
	{
		f[p][j][k][0] = f[p][j][k][1] = 0;
		f[p][j][k][0] = (f[q][j][k][0]+f[q][j][k][1])%mo;
		if (s1[i]==s2[j] && j>0 && k>0)
		f[p][j][k][1] = (f[q][j-1][k-1][0]+f[q][j-1][k-1][1])%mo;
		if (s1[i]==s2[j] && j>0)
		(f[p][j][k][1] += f[q][j-1][k][1])%=mo;
	}

	printf("%lld\n",(f[q][m][K][0]+f[q][m][K][1])%mo);
	return 0;
}
