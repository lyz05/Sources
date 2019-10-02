#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 1000000+12;
int a[N],n,T;


int main()
{
	//freopen("A.in","r",stdin);
	//freopen(".out","w",stdout);

	cin >> T;
	while (T --)
	{
		cin >> n;
		for (int i=1;i<=n;i ++) cin >> a[i];
		int ans = 0,minn = 1e9+7;
		for (int i=n;i>=1;i --) 
		{
			if (a[i]>minn) ans ++;
			minn = min(minn,a[i]);
		}
		cout << ans << endl;
	} 
	
	return 0;
}
(((()()())))
