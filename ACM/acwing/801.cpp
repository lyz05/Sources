#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000 +2;
int n; 

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) 
	{
		int t,ans = 0;
		cin >> t;
		while (t)
		{
			ans += t&1;
			t >>= 1;
		}
		cout << ans << " ";
	} 
	return 0;
} 
