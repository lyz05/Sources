#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 12,mo = 2009;
typedef int Matrix[N*10][N*10];
int n,t,len;
Matrix A,F,I;

void mul(Matrix &A,Matrix &B,Matrix &C)
{
	Matrix tmp;
	memset(tmp,0,sizeof tmp);
	for (int i=1;i<=len;i ++)
	for (int k=1;k<=len;k ++)
	if (A[i][k])
	for (int j=1;j<=len;j ++)
	if (B[k][j])
		(tmp[i][j] += (A[i][k]*B[k][j])%mo)%=mo;
	memcpy(C,tmp,sizeof tmp);
}

void pow(Matrix &X,int y,Matrix &F)
{
	Matrix ret;
	memcpy(ret,I,sizeof I);
	while (y)
	{
		if (y&1) mul(ret,X,ret);
		mul(X,X,X);
		y >>= 1;
	}
	memcpy(F,ret,sizeof ret);
}

int main()
{
	freopen("1036.in","r",stdin);
	//freopen(".out","w",stdout);

	scanf("%d%d",&n,&t);
	for (int i=1;i<=n;i ++)
	{
		scanf("\n");
		for (int j=1;j<=n;j ++)
		{
			int val;char ch;
			scanf("%c",&ch);
			val = ch - '0';
			for (int k=1;k<val;k ++) 
				A[i*10+k][i*10+k+1]=1;
			if (val) 
				A[i*10+val][j*10+1]=1;
		}
	}
	len = n*10+10;
	for (int i=1;i<=len;i ++) I[i][i] = 1;
	pow(A,t,F);
	printf("%d\n",F[11][n*10+1]);
	return 0;
}
