#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

double h,s1,v,l,k;
int n;

int main()
{
	scanf("%lf %lf %lf %lf %lf %D",&h,&s1,&v,&l,&k,&n);
	double t1=sqrt((h-k)/5),t2=sqrt(h/5);
	double d1=s1-v*t2,d2=s1-v*t1+l;
	int tot=0;
	for (int i=0;i<=n-1;i++)
	{
		if (i>=d1-0.00001 && i<=d2+0.00001) tot ++;
	}
	printf("%d\n",tot);
	return 0;
}
