#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000+2;
int a[N][N],n,m,q,sum[N][N];

int main()
{
	cin >> n >> m >> q;
	for (int i=1;i<=n;i ++)
		for (int j=1;j<=m;j ++)
		{
			cin >> a[i][j];
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
		}
	while (q --)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] -sum[x2][y1-1] - sum[x1-1][y2]+ sum[x1-1][y1-1] << endl;
	}
	return 0;
} 
