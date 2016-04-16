#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1005,mo = 1000000007;
int n,m,k;

const int NN = N;
struct Matrix
{
	int num[NN][NN],n,m;
	void init()
	{
		for (int i=0;i<=n;i ++)
			for (int j=0;j<=m;j ++)
				num[i][j] = (i==j);
	}
	void clear1(int x,int y) {n = x,m = y,memset(num,0,sizeof num);}

}IN,OUT,NOW,UNIT,TMP1,TMP,TMP2;

void mult(Matrix &a, Matrix &b,Matrix &ret)
{
	TMP1.clear1(a.n,b.m);
	for (int i=0;i<=a.n;i ++)
	for (int j=0;j<=a.m;j ++)
	if (a.num[i][j])
	for (int k=0;k<=b.m;k ++)
	if (b.num[j][k])
	{
		(TMP1.num[i][k] += (long long)a.num[i][j]*b.num[j][k]%mo)%=mo;
	}
	ret = TMP1;
}

void pow(Matrix &a,Matrix &ret,int y)
{
	TMP.clear1(a.n,a.m);
	TMP.init();
	while (y)
	{
		if (y & 1) mult(TMP,a,TMP);
		mult(a,a,a);
		y >>= 1;
	}
	ret = TMP;
}

int main()
{
	freopen("3545.in","r",stdin);
	//freopen("3545.out","w",stdout);

	scanf("%d%d",&n,&k);
	
	OUT.n = n+1, OUT.m = k+1;
	IN.n = k+1, IN.m = n+1;
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<=k;j ++) scanf("%d",&OUT.num[i][j]),OUT.num[i][j]%=mo;
		for (int j=1;j<=k;j ++) scanf("%d",&IN.num[i][j]),IN.num[i][j]%=mo;
	}
	OUT.num[n+1][k+1] = IN.num[k+1][n+1] = 1;
	for (scanf("%d",&m);m;m --)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		OUT.num[y][k+1] = 1;
		mult(IN,OUT,UNIT);
		pow(UNIT,NOW,z);
		mult(OUT,NOW,TMP2);
		printf("%d\n",TMP2.num[x][k+1]);
		OUT.num[y][k+1] = 0;
	}
	
	return 0;
}
