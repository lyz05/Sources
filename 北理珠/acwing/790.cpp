#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

double n; 
bool flag;

bool judge(double x)
{
	return x*x*x<=n;
}

int main()
{
	scanf("%lf",&n);
	if (n<0) flag = 1,n = -n;
	double l = 0,r = n;
	while ((r-l)>=0.0000001)
	{
		double mid = (l+r)/2;
		if (judge(mid))
			l = mid;
		else r = mid;
	}
	printf("%.6lf",flag?-l:l);
	return 0;
} 
