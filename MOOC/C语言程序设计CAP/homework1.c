#include <stdio.h>

int main()
{
	int n = 0,ans = 0;
	scanf("%d",&n);
	while (n != 0)
	{
		ans = ans*10+n%10;
		n = n / 10;
	}
	printf("%d",ans);
}