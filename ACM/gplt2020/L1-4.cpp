#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1000+8;
int n;
double a[N],sum;

int main()
{
	while (cin >> n)
	{
		sum = 0;
		for (int i=1;i<=n;i ++)
		{
			cin >> a[i];
			a[i] = 1.0/a[i];
			sum += a[i];
		}
		double avg = n*1.0/sum;
		printf("%.2lf\n",avg);
	}
	return 0;
}
