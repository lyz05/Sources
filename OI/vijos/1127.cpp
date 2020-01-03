#include <cstdio>

using namespace std;

int k,i;
double s;

int main()
{
	scanf("%d",&k);
	for (i=1;s<=k;i++)
	{
		s=s+(double)1/i;
	}
	printf("%d\n",i-1);
	return 0;
}
