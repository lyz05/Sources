#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 85,yw = 100000000,ws = 8;
struct bign
{
	int len,a[100];
	bign(){
		len = 1;
		memset(a,0,sizeof a);
	}
	bign(const int &X)
	{
		memset(a,0,sizeof a);
		int x = X;
		//bign C;
		len = 0;
		while (x)
		{
			a[++ len] = x%yw;
			x = x/yw;
		}
		//return C;
	}
	bign operator + (const bign &B)const
	{
		bign c;
		int lenn = max(len,B.len),jw = 0;
		for (int i=1;i<=lenn;i ++)
		{
			c.a[i] = a[i]+B.a[i]+jw;
			jw = c.a[i]/yw;
			c.a[i] %= yw;
		}
		if (jw) c.a[++ lenn] = jw;
		c.len = lenn;
		return c;
	}
};
int n,m;
int a[N][N];
bign ans,f[N][N],v[N][N];

bign max(bign A,bign B)
{
	if (A.len>B.len) return A;
	if (A.len<B.len) return B;
	int len = A.len;
	for (int i=len;i;i --)
	{
		if (A.a[i]>B.a[i]) return A;
		if (A.a[i]<B.a[i]) return B;
	}
	return B;
}

void print(const bign &A)
{
	if (A.len==0) return;
	printf("%d",A.a[A.len]);
	for (int i=A.len-1;i;i --)
	{
		for (int j=1,x=1;j<=ws;j ++,x*=10) 
			if (A.a[i]/x==0) printf("0");
		printf("%d",A.a[i]);
	}
	puts("");
}

int main()
{
	freopen("1378.in","r",stdin);
	//freopen("1378.out","w",stdout);

	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i ++)
	for (int j=1;j<=m;j ++) 
		scanf("%d",&a[i][j]);
	for (int j=1;j<=n;j ++)
	{
		memset(f,0,sizeof f);
		memset(v,0,sizeof v);
		bign tmp;

		for (int i=1;i<=m;i ++)
		{
			v[i][0] = a[j][i];
			for (int k=1;k<=m;k ++) 
				v[i][k] = v[i][k-1] + v[i][k-1];
		}
		for (int p=1;p<=m;p ++)
		for (int i=0,j=p-i;i<=p;i ++,j=p-i)
			if (i==0) 
				f[i][j] = f[i][j-1]+v[m-j+1][p];
			else if (j==0)
				f[i][j] = f[i-1][j]+v[i][p];
			else
				f[i][j] = max(f[i-1][j]+v[i][p],f[i][j-1]+v[m-j+1][p]);
		//tmp = 1;
		//tmp = v[1][2]+f[0][1];
		for (int i=1;i<=m;i ++)
			tmp = max(tmp,f[i][m-i]);
		ans = ans + tmp;
	}
	//ans = 100052;
	print(ans);
	return 0;
}
