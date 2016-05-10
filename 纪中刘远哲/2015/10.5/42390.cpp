#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 35,Mo = int(1e9) + 7;

typedef long long LL;

LL L,R;
int A,V[MAXN],C[22][2][12][12],S[22][2][12][12],F[22][2][12][12]; 
//C is the number S is the sum F is the sqr sum

int Calc(LL Lim)
{
	memset(C,0,sizeof C),memset(S,0,sizeof S),memset(F,0,sizeof F);
	int tot = 0;
	for(;Lim;Lim /= 10) V[++ tot] = (Lim % 10);
	C[tot + 1][1][0][0] = 1;
	for(int i = tot;i;i --)
	for(int j = 0;j < 2;j ++)
	for(int mo = 0;mo < A;mo ++)
	for(int b = 0;b < A;b ++)
		if (C[i + 1][j][mo][b])
			for(int ch = 0;ch < 10;ch ++)
				if (ch != A && (!(j && ch > V[i])))
				{
					int nj = (j && ch == V[i]),mot = (mo * 10 + ch) % A,nb = (b + ch) % A;
					int &nc = C[i][nj][mot][nb],&ns = S[i][nj][mot][nb],&nf = F[i][nj][mot][nb];
					nc = (nc + C[i + 1][j][mo][b]) % Mo;
					ns = (0ll + ns + 10ll * S[i + 1][j][mo][b] % Mo + C[i + 1][j][mo][b] * 1ll * ch % Mo) % Mo;
					nf = (0ll + nf + 100ll * F[i + 1][j][mo][b] % Mo + 20ll * ch * S[i + 1][j][mo][b] % Mo) % Mo;
					nf = (nf + ch * 1ll * ch * C[i + 1][j][mo][b] % Mo) % Mo;
				}
	int tmp = 0;
	for(int j = 0;j < 2;j ++)
		for(int mo = 1;mo < A;mo ++)
			for(int b = 1;b < A;b ++)
			tmp = (tmp + F[1][j][mo][b]) % Mo;
	return tmp;
}

void Work()
{
	scanf("%lld%lld%d", &L, &R, &A);
	printf("%d\n", (Calc(R) - Calc(L - 1) + Mo) % Mo);
}

int main()
{
	freopen("bachelor.in","r",stdin);
	int T;
	scanf("%d", &T);
	for(;T;T --) 
		Work();
	return 0;
}

