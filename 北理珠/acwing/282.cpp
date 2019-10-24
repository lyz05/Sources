#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300+7;
int n;
int f[N][N],a[N],sum[N];

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i],sum[i] = sum[i-1]+a[i],f[i][i] = 0;
	
	//memset(f,125,sizeof f);
	for (int len=2;len<=n;len ++)
		for (int i=1;i+len-1<=n;i ++)
		{
			int j = i+len-1;
			f[i][j] = 1e9+7;
			for (int k=i;k<j;k ++)
				f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+(sum[k]-sum[i-1])+(sum[j]-sum[k]));
		}
	cout << f[1][n] << endl;
	return 0;
} 
