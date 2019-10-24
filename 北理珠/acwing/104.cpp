#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
long long n,a[N],avg,sum;

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i];
	sort(a+1,a+1+n);
	if (n&1) avg = a[(n+1)>>1];
	else avg = (a[(n+1)>>1]+a[((n+1)>>1)+1])/2;
	for (int i=1;i<=n;i ++) sum += abs(a[i]-avg);
	cout << sum;
	return 0;
} 
