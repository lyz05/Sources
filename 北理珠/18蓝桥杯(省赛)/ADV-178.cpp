#include <cstdio>
#include <algorithm>
using namespace std;

int n,ans = 0;

int main()
{
	for (int i=1;i<1000;i ++) 
	{
		if (i%3==0 || i%5==0) ans += i;
	} 
	printf("%d\n",ans);
	return 0;	
} 
//1 1 2 3 5 8 13
