#include <stdio.h>
#include <math.h>

int pri(int n)
{
	int j = floor(sqrt(n)),i;
	for (i = 2;i <= j;i ++)
		if (n%i == 0) return 0;
	return 1;
}

int main()
{
	int i,n,m,tot = 2,ans = 0;
	scanf("%d %d",&n,&m);
	for (i=1;i<=m;i ++)
	{
		while (!pri(tot)) tot ++;
		if (i>=n) ans += tot;
		tot ++;
	}
	printf("%d",ans);
}