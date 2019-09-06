#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 55+12;
int n;
int a[N];

int main()
{
	for (int i=1;i<=4;i ++) a[i] = i;
	for (int i=5;i<N;i ++) a[i] = a[i-1] + a[i-3];
	while (cin >> n)
	{
		if (n==0) break;
		cout << a[n] << endl;
	} 
	return 0;
}
