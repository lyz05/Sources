#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100000 +2;
int n,a[N],ans; 
int map[N]; 

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) cin >> a[i];

	for (int i=1,j=1;i<=n && j<=n;)
	{
		while (!map[a[j]] && j<=n) map[a[j]] = 1,j ++;
		ans = max(ans,j-i);
		while (map[a[j]] && i<=j) map[a[i]] = 0,i ++;
	}
	cout << ans << endl;
	return 0;
} 
