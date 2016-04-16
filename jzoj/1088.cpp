#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 150,mo = 45989;

typedef int matrix[N][N];
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

int n,m,A,B,ans,tot = 1;
int t;
int e[N];
matrix st,f;

struct node
{
	int x,y,id,next;
} h[N<<1];

void add(int x,int y)
{
	h[++ tot].y = y;
	h[tot].x = x;
	h[tot].next = e[x];
	e[x] = tot;
}

int main()
{
	freopen("1088.in","r",stdin);
	
	scanf("%d%d%d%d%d",&n,&m,&t,&A,&B);
	for (int i=1;i<=m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for (int i=e[A];i;i=h[i].next) f[1][i] ++;
	for (int i=2;i<=tot;i ++)
		for (int j=2;j<=tot;j ++)
			if (h[i].y==h[j].x && i!=(j^1)) st[i][j] ++;
	M.init(tot);
	M.pow(st,t-1,st);
	M.mul(f,st,f);
	for (int i=e[B];i;i=h[i].next) 
		(ans += f[1][i^1])%=mo;
	printf("%d\n",ans);
	return 0;
}
