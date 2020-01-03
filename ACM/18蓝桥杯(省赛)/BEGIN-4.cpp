#include <cstdio>
using namespace std;

const int mo = 10007;
int n,a,b,c;

int main()
{
	scanf("%d",&n);
	a = 0;b = 1;c = 1;
	//0   1     2
	for (int i=3;i<=n;i ++)
	{
		a = b;b = c;c = (a+b)%mo;
	}
	printf("%d\n",c);
	return 0;	
} 
//1 1 2 3 5 8 13
