#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 500000+5,Limit = 5e8;
int a[2][N];
int n;
bool flag;

int middle(int x,int y,int z)
{
	if ((x>=y && y>=z) || (z>=y && y>=x)) return y;
	if ((x>=z && z>=y) || (y>=z && z>=x)) return z;
	if ((y>=x && x>=z) || (z>=x && x>=y)) return x;
	return -1;
}

int main()
{
	freopen("median.in","r",stdin);
	//freopen("median.out","w",stdout);

	scanf("%d",&n);
	flag = 1;
	for (int i=1;i<=n;i ++) 
	{
		scanf("%d",&a[0][i]);
		if (i!=1 && a[0][i]==a[0][i-1]) flag = 0;
	}
	if (flag)
	{
		if (n%2==0) 
		{
			printf("%d\n",n/2-1);
			for (int i=1;i<=n/2;i ++) printf("%d ",a[0][1]);
			for (int i=n/2+1;i<=n;i ++) printf("%d ",a[0][2]);
		}
		else 
		{
			printf("%d\n",n/2);
			for (int i=1;i<=n;i ++) printf("%d ",a[0][1]);
		}
		puts("");
		return 0;
	}
	int p = 0, q = 1;
	for (int ans=1;ans*n<=Limit;ans ++,p^=1,q^=1)
	{
		bool flag = 1;
		a[q][1] = a[p][1];a[q][n] = a[p][n];
		for (int i=2;i<n;i ++)
		{
			a[q][i] = middle(a[p][i],a[p][i-1],a[p][i+1]);
			if (a[p][i]!=a[q][i]) flag = 0;
		}
		if (flag)
		{
			printf("%d\n",ans-1);
			for (int i=1;i<=n;i ++) printf("%d ",a[p][i]);
			puts("");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
