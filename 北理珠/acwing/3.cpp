#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4+7;
int n,V;
int v[N],w[N],f[N][N];

int main()
{
	cin >> n >> V;
	for (int i=1;i<=n;i ++) 
		cin >> v[i] >> w[i];
	
	for (int i=1;i<=n;i ++)
		for (int j=0;j<=V;j++)
		{
			if (j-v[i]>=0)
				f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]),
				f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
			else f[i][j] = f[i-1][j];
		}
	cout << f[n][V] << endl;
	return 0;
} 
