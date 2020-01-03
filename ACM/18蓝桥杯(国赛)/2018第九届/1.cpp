#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int sum = 200;
int i,j,k,ans = 1e9+7;

int main()
{
	for (int i=1;i<=sum;i ++)
		for (int j=1;i+j*2<=sum;j ++)
		{
			if (j!=i*10) continue;
			int k = (sum-(i+2*j));
			if (k%5 != 0) continue;
			k /= 5;
			if (i+j+k<ans)
			{
				ans = i+j+k;
				cout << i << " " << j << " " << k << endl; 
			}
		}
	cout << ans << endl;
	return 0;
} 
