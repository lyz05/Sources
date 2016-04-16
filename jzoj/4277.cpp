#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 45,mo = int(1e9)+9;
typedef int matrix[N][N];
matrix T,F,All,Cur,Bak,Tmp,Lst;
int n,m,c[N],x[N],ans,v[N];

void clear(matrix &a) //��ֵΪ��λ����
{
	memset(a,0,sizeof a);
	for (int i=0;i<m;i ++) a[i][i] = 1;
}
void mul(matrix &c,matrix &a,matrix &b)
{
	memset(Tmp,0,sizeof Tmp);
	for (int i=0;i<m;i ++)
	for (int k=0;k<m;k ++)
	if (a[i][k])
	for (int j=0;j<m;j ++)
	if (b[k][j])
		(Tmp[i][j] += (1ll*a[i][k]*b[k][j]) % mo) %= mo;
	memcpy(c,Tmp,sizeof Tmp);
}

void add(matrix &c,matrix &a,matrix &b)
{
	for (int i=0;i<m;i ++)
		for (int j=0;j<m;j ++)
			c[i][j] = (a[i][j]+b[i][j]) % mo;
}
void work()
{
	clear(All);
	for (int i=1;i<=n;i ++)//ö��ÿһά
	{
		clear(Cur);//��ǰά�ȵĳ˻�
		int cnt = 0;
		for (;x[i];x[i]>>=1) v[++ cnt] = x[i];
		if (cnt) mul(Cur,Cur,T);
		memcpy(Lst,T,sizeof T);
		for (cnt --;cnt;cnt --)
		{
			//Lst = A^mid, Cur = F
			mul(Bak,Cur,Lst);
			add(Cur,Bak,Cur);
			mul(Lst,Lst,Lst);
			if (v[cnt] & 1)//����Ϊ����ʱ
			{
				mul(Lst,Lst,T);
				add(Cur,Lst,Cur);
			}
		}
		for (int j=0;j<m;j ++) Cur[j][j]=(Cur[j][j]+1)%mo;
		//�ӵ�λ����
		mul(All,All,Cur);
	}
	mul(F,F,All);
	ans = F[0][0];
}

int main()
{
	freopen("recursion.in","r",stdin);
	//freopen("recursion.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i ++) scanf("%d",c + i);
	for (int i=0;i<m;i ++) scanf("%d",&F[0][i]);
	for (int i=1;i<=n;i ++) scanf("%d",&x[i]),x[i] --;
	//���ݶ���
	for (int i=0;i+1<m;i ++)
		T[i+1][i] = 1;
	for (int i=0;i<m;i ++)
		T[i][m-1] = c[m-i];
	//T Ϊ�������ת�ƾ���
	work();
	printf("%d\n",ans);
	return 0;
}
