#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 200000+8;
int n,ans;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);

	cin >> n;
	for (int i=1;i<=n;i ++) 
	{
		int t;
		cin >> t;
		if (t&1) ans ++;
	}
	cout << min(ans,n-ans);

	return 0;
}
