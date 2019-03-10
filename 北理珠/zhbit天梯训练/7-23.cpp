#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i ++)
	{
		char c;
		double d;
		scanf(" %c %lf",&c,&d);
		if (c=='F') d*=1.09;else d/=1.09;
		printf("%.2f\n",d);
	} 
	return 0;
}
