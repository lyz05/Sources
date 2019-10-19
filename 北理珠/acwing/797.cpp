#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000+2;
int n,m,a[N],b[N];

int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i ++) cin >> a[i];
	for (int i=1;i<=m;i ++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		b[x] += z;
		b[y+1] -= z;
	}
	for (int i=1;i<=n;i ++) b[i] = b[i-1]+b[i];
	for (int i=1;i<=n;i ++)
	{
		a[i] += b[i];
		cout << a[i] << " ";
	}
	return 0;
} 
