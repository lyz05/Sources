#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 45,Mo = int(1e9) + 9;
typedef int Matrix[MAXN][MAXN];
Matrix T,F,All,Cur,Bak,Tmp,Lst;
int N,M,C[MAXN],X[MAXN],V[MAXN],ans;

void clear(Matrix &a) //赋值为单位矩阵
{
	memset(a,0,sizeof a);
	for (int i=0;i<M;i ++) a[i][i] = 1;
}

void mul(Matrix &c,Matrix &a,Matrix &b)
{
	memset(Tmp,0,sizeof Tmp);
	for (int i=0;i<M;i ++)
	for (int k=0;k<M;k ++)
	if (a[i][k])
	for (int j=0;j<M;j ++)
	if (b[k][j])
		(Tmp[i][j] += (1ll*a[i][k]*b[k][j]) % Mo) %= Mo;
	memcpy(c,Tmp,sizeof Tmp);
}

void add(Matrix &c,Matrix &a,Matrix &b)
{
	for (int i=0;i<M;i ++)
		for (int j=0;j<M;j ++)
			c[i][j] = (a[i][j]+b[i][j]) % Mo;
}
void work()
{
	clear(All);
	for (int i=1;i<=N;i ++)//枚举每一维
	{
		clear(Cur);//当前维度的乘积
		int cnt = 0;
		for (;X[i];X[i]>>=1) V[++ cnt] = X[i];
		if (cnt) mul(Cur,Cur,T);
		memcpy(Lst,T,sizeof T);
		for (cnt --;cnt;cnt --)
		{
			//Lst = A^mid, Cur = F
			mul(Bak,Cur,Lst);
			add(Cur,Bak,Cur);
			mul(Lst,Lst,Lst);
			if (V[cnt] & 1)//当幂为奇数时
			{
				mul(Lst,Lst,T);
				add(Cur,Lst,Cur);
			}
		}
		for (int j=0;j<M;j ++) Cur[j][j]=(Cur[j][j]+1)%Mo;
		//加单位矩阵
		mul(All,All,Cur);
	}
	mul(F,F,All);
	ans = F[0][0];
}

int main()
{
	freopen("recursion.in","r",stdin);
	//freopen("recursion.out","w",stdout);
	
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i ++) scanf("%d",C + i);
	for (int i=0;i<M;i ++) scanf("%d",&F[0][i]);
	for (int i=1;i<=N;i ++) scanf("%d",&X[i]),X[i] --;
	//数据读入
	for (int i=0;i+1<M;i ++)
		T[i+1][i] = 1;
	for (int i=0;i<M;i ++)
		T[i][M-1] = C[M-i];
	//T 为构造出的转移矩阵
	work();
	printf("%d\n",ans);
	return 0;
}

