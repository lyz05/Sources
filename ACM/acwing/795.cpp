#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000+7;
int a[N],n,m,sum[N];

int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i ++) cin >> a[i],sum[i] = sum[i-1] + a[i];
	while (m --)
	{
		int x,y;
		cin >> x >> y;
		cout << sum[y] - sum[x-1] << endl;
	}
	return 0;
} 
