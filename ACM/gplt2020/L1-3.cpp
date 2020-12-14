#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

double x,z;
int y;

int main()
{
	while (cin >> x >> y >> z)
	{
		double k=0,ans=0;
		if (y==0) {
			k=2.455;
		} else k=1.26;
		ans=x*k;
		printf("%.2lf %s\n",ans,(ans<=z)?"^_^":"T_T");
	}
	return 0;
}
