#include <cstdio>
#include <algorithm>
using namespace std;

int n,ans = 1,mo = 1000000;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++) 
	{
		ans = (ans*i)%mo;
		while (ans%10==0) ans/=10;
		//printf("%d %d\n",i,ans);
	}
	printf("%d\n",ans%10);
	return 0;	
} 
//1 1 2 3 5 8 13
