#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
LL mo,A,C,x0,n,g;

LL mul(LL x,LL y)
{
	LL ret = 0;
	while (y)
	{
		if (y & 1) (ret += x)%=mo;
		(x += x)%=mo;
		y >>= 1;
	}
	return ret;
}


const int NN = 10;//mo = 1e9+7;
struct Matrix
{
	LL num[NN][NN],Node;
	Matrix()
	{
		memset(num,0,sizeof num);
		Node = 3;
	}
	void init() {for (int i=0;i<=Node;i ++) num[i][i] = 1;}
	Matrix operator *(const Matrix &b) const
	{
		Matrix ret;
		for (int i=0;i<=Node;i ++)
		for (int j=0;j<=Node;j ++)
		if (num[i][j])
		for (int k=0;k<=Node;k ++)
		if (b.num[j][k])
		{
			//ret.num[i][k] += num[i][j]*b.num[j][k];
			(ret.num[i][k] += mul(num[i][j],b.num[j][k])%mo)%=mo;
		}
		return ret;
	}
	Matrix operator +(const Matrix &b) const
	{
		Matrix ret;
		for (int i=0;i<=Node;i ++)
			for (int j=0;j<=Node;j ++)
				ret.num[i][j] = (num[i][j]+b.num[i][j])%mo;
				//ret.num[i][j] = num[i][j]+b.num[i][j];
		return ret;
	}
	friend Matrix operator ^(Matrix a,LL y)
	{
		Matrix ret;
		ret.init();
		while (y)
		{
			if (y & 1) ret = ret*a;
			a = a*a;
			y >>= 1;
		}
		return ret;
	}
} a,f;


int main()
{
	freopen("3366.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%lld%lld%lld%lld%lld%lld",&mo,&A,&C,&x0,&n,&g);
	f.num[1][1] = x0,f.num[1][3] = 1;
	a.num[1][1] = A,a.num[1][2] = 1,a.num[3][1] = C,a.num[3][3] = 1;
	f = f*(a^n);
	printf("%lld\n",f.num[1][1]%g);
	return 0;
}
