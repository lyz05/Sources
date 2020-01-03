#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000+7;
int n;
int f[N],a[N],ans;

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) 
		cin >> a[i];
	for (int i=1;i<=n;i ++)
	{
		for (int j=1;j<i;j ++)
			if (a[j]<a[i])
			{
				f[i] = max(f[i],f[j]);
			}
		f[i] ++;
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
	return 0;
} 
