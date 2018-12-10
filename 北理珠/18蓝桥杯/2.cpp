#include<cstdio>
using namespace std;

const int N = 10000;
int a[N],n,L,R,ans;

int main()
{
	//freopen("2.in","r",stdin);
	
	scanf("%d%d%d",&n,&L,&R);
	for (int i=2;i<=n;i ++)
	{
		for (int j=1;i*j<=R;j ++)
		{
			a[i*j] ^= 1;
		}
	}
	for (int i=L;i<=R;i ++)
	{
		if (a[i]) ans ++;
	}
	printf("%d\n",ans);
	return 0;
} 
//10 3 6
//011100
