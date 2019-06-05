#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000+7;
int n,k,f[N],ans = 0;

int main()
{
	cin >> n >> k;
	
	for (int i=0;i<=n;i ++) f[i] = 1e9+7;
	f[0] = 0;
	
	for (int i=1;i<n;i ++)
	{
		if (i-k>=0)	
			f[i] = min(f[i-1]+1,f[i-k]+1);
		else f[i] = f[i-1]+1;
		ans = max(ans,f[i]);
	}
	//for (int i=0;i<n;i ++) cout << f[i] << " ";
	cout << ans << endl;
	return 0;
} 
