#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500+7;
int n;
int f[N][N],a[N][N],ans;

int main()
{
	ans = -1e9+7;

	cin >> n;
	for (int i=1;i<=n;i ++) 
		for (int j=1;j<=i;j ++)
			cin >> a[i][j];
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=i;j ++)
		{
			if (i==j)
				f[i][j] = f[i-1][j-1]+a[i][j]; 
			else if (j==1)
				f[i][j] = f[i-1][j]+a[i][j];
			else f[i][j] = max(f[i-1][j],f[i-1][j-1])+a[i][j];
			ans = max(ans,(i==n)?f[i][j]:0);
		}
	cout << ans << endl;
	return 0;
} 
