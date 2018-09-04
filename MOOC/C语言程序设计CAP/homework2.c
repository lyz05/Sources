#include <stdio.h>

int main()
{
	int n,min,hour,ans;
	scanf("%d",&n);
	min = n % 100;
	hour = n / 100;
	hour = (hour + 24 - 8) % 24;
	ans = hour * 100 + min;
	printf("%d",ans);
	return 0;
}