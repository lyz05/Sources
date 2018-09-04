#include <stdio.h>

int main()
{
	int n,ans1 = 0,ans2 = 0;
	scanf("%d",&n);
	while (n!=-1)
	{
		if (n % 2 == 1) ans1 ++;else ans2 ++; 
		scanf("%d",&n);
	}
	printf("%d %d",ans1,ans2);
	return 0;
}