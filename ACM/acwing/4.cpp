#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100+7;
int n,V;
int v[N],w[N],s[N],f[N][N][N];

int main()
{
	cin >> n >> V;
	for (int i=1;i<=n;i ++) 
		cin >> v[i] >> w[i] >> s[i];
	
	for (int i=1;i<=n;i ++)
	{
		for (int j=0;j<=V;j ++) f[i][j][0] = f[i-1][j][s[i-1]];
		for (int k=1;k<=s[i];k ++)
		for (int j=0;j<=V;j++)
		{
			if (j-v[i]>=0)
				f[i][j][k] = max(f[i][j][k-1],f[i][j-v[i]][k-1] + w[i]);
			else f[i][j][k] = f[i][j][k-1]; 
		}
	}
	cout << f[n][V][s[n]] << endl;
	return 0;
} 
