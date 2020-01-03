#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int K = 35,mo = 1234567891;

typedef LL matrix[K][K];
struct Matirx
{
	int size;
	void init(int Size) {size = Size;}
	void clear(matrix &a) //赋值为单位矩阵
	{
		memset(a,0,sizeof a);
		for (int i=0;i<=size;i ++) a[i][i] = 1;
	}
	void mul(matrix &a,matrix &b,matrix &c)
	{
		matrix ret;
		memset(ret,0,sizeof ret);
		for (int i=0;i<=size;i ++)
		for (int k=0;k<=size;k ++)
		if (a[i][k])
		for (int j=0;j<=size;j ++)
		if (b[k][j])
			(ret[i][j] += (1ll*a[i][k]*b[k][j]) % mo) %= mo;
		memcpy(c,ret,sizeof ret);
	}
	void pow(matrix &a,int y,matrix &c)
	{
		matrix ret;
		clear(ret);
		while (y)
		{
			if (y & 1) mul(ret,a,ret);
			mul(a,a,a);
			y >>= 1;
		}
		memcpy(c,ret,sizeof ret);
	}
} M;

int n,k;
LL mi;
matrix a,ans;

void work()
{
	scanf("%d%d",&n,&k);
	memset(ans,0,sizeof ans);memset(a,0,sizeof a);
	ans[1][1] = 1;mi = 1;
	for (int i=1;i<=k;i ++)
	{
		if (i>1) a[i-1][i] = 1;
		a[i][i] = i;
		(mi *= i) %= mo;
	}
	a[k+1][k+1] = a[k][k+1] = 1;
	M.init(k+1);
	M.pow(a,n-1,a);
	M.mul(ans,a,ans);
	LL Ans = ((ans[1][k]+ans[1][k+1])%mo*mi)%mo;
	printf("%lld\n",Ans);
}

int main()
{
	freopen("1054.in","r",stdin);
	
	int T;
	scanf("%d",&T);
	while (T --) work();
	return 0;
}
