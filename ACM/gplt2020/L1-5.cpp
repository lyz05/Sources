#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 10+8;
int n;
int a[N],sum;
bool p[N];

int main()
{
	while (true)
	{
		int maxx = 0;
		memset(p,0,sizeof p);
		for (int i=1;i<=6;i ++)
		{
			if (!(cin >> a[i])) 
				return 0;
			if (i<=4)
				maxx = max(maxx,a[i]);
		}
		for (int i=1;i<=4;i ++){
			if (maxx-a[i]>a[6]) {
				p[i] = 1;
			}
			if (a[i]<a[5]) {
				p[i] = 1;
			}
		}
		int sum = 0,k = 0;
		for (int i=1;i<=4;i ++)
			if (p[i])
				sum += p[i],k = i;
		if (sum==0)
			cout << "Normal" << endl;
		else if (sum==1)
			printf("Warning: please check #%d!\n",k);
		else 
			cout << "Warning: please check all the tires!" << endl;
	}
	return 0;
}
