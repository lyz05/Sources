#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 55;
int n,m,nf,t,S,T,K,Node;
int f[15][N],p[10];

const int NN = N,mo = 10000;
struct Matrix
{
	int num[NN][NN];
	Matrix()
	{
		memset(num,0,sizeof num);
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
			(ret.num[i][k] += num[i][j]*b.num[j][k]%mo)%=mo;
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
	friend Matrix operator ^(Matrix a,int y)
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
} ans,M[12];

void val(int x,int y)
{
	for (int i=0;i<12;i ++) M[i].num[x][y] = M[i].num[y][x] = 1;
}
void clear1(int x,int y){for (int i=0;i<n;i ++) M[x].num[y][i] = 0;}
void clear2(int x,int y){for (int i=0;i<n;i ++) M[x].num[i][y] = 0;}

int main()
{
	freopen("2288.in","r",stdin);
	//freopen("2288.out","w",stdout);

	scanf("%d%d%d%d%d",&n,&m,&S,&T,&K);
	Node = n;
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		val(x,y);
	}
	scanf("%d",&nf);
	while (nf --)
	{
		scanf("%d",&t);
		for (int i=0;i<t;i ++) scanf("%d",&p[i]);
		for (int i=0;i<12;i ++) f[i][p[i%t]] = 1;
	}
	for (int i=0;i<12;i ++)
	for (int j=0;j<n;j ++)
		if (f[i][j]) clear1(i,j),clear2((i-1+12)%12,j);
	for (int i=1;i<12;i ++) M[i] = M[i-1]*M[i]; //Ç°×º»ý
	
	ans = M[11]^(K/12);
	if (K%12) ans = ans * M[K%12-1];
	printf("%d\n",ans.num[S][T]);
	return 0;
}
