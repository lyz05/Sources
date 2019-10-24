#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
long long n,a[N];

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i ++) a[i] = a[i-1]+a[i];
	for (int i=1;i<=n;i ++) a[i] = a[i-1]+a[i];
	cout << a[n-1];
	return 0;
} 
