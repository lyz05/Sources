#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
using namespace std;

const int N = 4000002,mo = 26;
char s[2][20000][5001];
char st[N];
int tot[2],p,n,m,l;
long long ans;
unsigned int Pow[N],hs[N];
map <unsigned int,int> hashst,used;
int hash(int l,int r)
{
	return hs[r] - hs[l-1]*Pow[r-l+1];
}

int main()
{
	freopen("4126.in","r",stdin);
	//freopen(".out","w",stdout);

	Pow[0] = hs[0] = 1;

	scanf("%d%d%d%d",&n,&m,&tot[0],&tot[1]);
	for (int i=1;i<max(tot[0],tot[1]);i ++) Pow[i] = Pow[i-1]*mo;
	l = (tot[0]+tot[1])>>1;
	if (tot[0]>=tot[1]) p = 0; else p = 1;
	for (int i=1;i<=n;i ++) scanf("%s",s[p][i]);//,s[p][i] = string(st);
	for (int i=1;i<=m;i ++) scanf("%s",s[p^1][i]);//,s[p^1][i] = string(st);
	if (tot[0]<tot[1]) swap(tot[0],tot[1]),swap(n,m);

	for (int i=1;i<=m;i ++)
	{
		unsigned int h = 0;
		for (int j=0;j<tot[1];j ++)
			h=h*mo+s[1][i][j]-'a';
		hashst[h] ++;
	}
	for (int i=1;i<=n;i ++)
	{
		//used.clear();
		for (int j=0;j<tot[0];j ++)
			hs[j+1] = hs[j]*mo+s[0][i][j]-'a';
		for (int j=1;j<=l;j ++)
		{
			unsigned int hs=hash(j,l)*Pow[j-1]+hash(1,j-1);
			//if (used[hs]) continue;
			//used[hs] = 1;
			ans += hashst[hs-hash(l+1,tot[0])*Pow[tot[1]]];
		}
	}
	printf("%lld\n",ans);

	return 0;
}
