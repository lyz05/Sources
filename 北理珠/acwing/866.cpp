#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 2e5+5;
int n,m,h[N],ans;

bool prime(int x)
{
	if (x==1) return 0;
	for (int i=2;i<=floor(sqrt(x));i ++)
	{
		if (x%i==0) return 0;
	}
	return 1;
}

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) 
	{
		int x;
		cin >> x;
		cout << (prime(x)?"Yes":"No") << endl;
	}
	return 0;
} 
