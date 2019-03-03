//有性能问题 
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;
const int N = 55;
LL n,ans = 1;

int main()
{
	scanf("%I64d",&n);
	
	for (int i=2;n!=1;i ++)
	{
		if (n%i==0) ans *= i;
		while (n%i==0) n/=i;
	}
	printf("%I64d",ans);
	return 0;
} 
//1 1 2 3 5 8 13
