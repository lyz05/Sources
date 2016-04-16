#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int mo = 1e9+7;

const int N = 200+5;
int n,k;
LL C[15][15],f[N][N][10];
const int flag[10][10]={
	{1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
	{1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
	{1 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 },
	{1 ,2 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 },
	{1 ,2 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 },
	{1 ,1 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0 },
	{1 ,0 ,2 ,0 ,0 ,0 ,1 ,0 ,0 ,0 },
	{1 ,3 ,0 ,2 ,1 ,0 ,0 ,1 ,0 ,0 },
	{1 ,2 ,1 ,1 ,0 ,2 ,0 ,0 ,1 ,0 },
	{1 ,4 ,0 ,4 ,2 ,0 ,0 ,4 ,0 ,1 }
},dt1[10]={12,9,6,6,6,3,0,3,0,0}
 ,dt2[10]={4 ,2,1,1,0,0,0,0,0,0};

void prepar()
{
	C[0][0] = 1;
	for (int i=1;i<15;i ++)
	{
		C[i][0] = 1;
		for (int j=1;j<=i;j ++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1])%mo;
	}

	f[0][0][0]=1;
	f[0][1][1]=4;f[0][1][2]=4;
	f[0][2][3]=4;f[0][2][4]=2;f[0][2][5]=8;f[0][2][6]=2;
	f[0][3][7]=4;f[0][3][8]=4;
	f[0][4][9]=1;
	//n=0时同构的三角形
}

int main()
{
	//freopen("magic.in","r",stdin);
	//freopen("magic.out","r",stdout);
	scanf("%d%d",&n,&k);
	prepar();
	
	for (int i=0;i<n;i ++)
	for (int j=0;j<10;j ++)
	for (int p=0;p<=k;p ++)
	if (f[i][p][j])
		for (int q=0;q<10;q++)//状态能够转移
		if (flag[j][q])
		{
			int d1=dt1[q],d2=dt2[q];
			for(int r=0;p+r<=k && r<=d2;r++)//枚举选两个
			for(int t=0;p+r+t<=k && t<=d1-2*r;t++)//枚举选一个
			{
				(f[i+1][p+r+t][q]+=((f[i][p][j]*C[d2][r])%mo*C[d1-2*r][t])%mo*flag[j][q])%=mo;
			}
		}
	LL ans = 0;
	for (int j=0;j<10;j ++) (ans += f[n][k][j])%=mo;
	for (int i=1;i<=k;i ++) (ans *= i)%=mo;
	printf("%lld\n",ans);
	return 0;
}
