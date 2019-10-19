#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n,m,a[N];

int main()
{
	cin >> n >> m;
	for (int i=0;i<n;i ++) cin >> a[i];
	sort(a,a+n);
	for (int i=0;i<m;i ++) cout << a[i] << " ";
	return 0;
} 
