#include <cstdio>
using namespace std;

typedef long long LL;
const int M = 10000;
int a[M],n,k,now;

LL C(int n,int m)
{
	LL ret = 1;
	for (int i = n-m+1;i <= n;i ++) ret *= i;
	for (int i = 1;i <= m;i ++) ret /= i;
	return ret;
}

void work(int n,int kk)
{
	for (int i=n-k+1;i<=n;i ++) a[i] = 1;
	kk --;
	while (kk --)
	{
		int i,tot = 0;
		for (i=n;i>=1;i--) if (a[i]) break;
		for (;i>=1;i--) 
		{
			if (!a[i]) break;
			tot ++;
		}
		for (int j=n;j>=i;j--) a[j] = 0;
		for (int j=n;j>=n-tot+2;j--) a[j] = 1;
		a[i] = 1;
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	if (k==1) 
	{
		printf("1");
		for (int i=1;i<n;i ++) printf("0");
		puts("");
	} else 
	{
		k --;
		now = k;
		while (C(now,k)<n)
		{
			n -= C(now,k);
			now ++;
		}
		printf("1");
		work(now,n);
		for (int i=1;i<=now;i++) printf("%d",a[i]);
		puts("");
	}
	return 0;
}
