#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	//freopen("0.in","r",stdin);
	//freopen(".out","w",stdout);
	int n = 1200000,ans = 0;
	for (int i=1;i<=n;i ++)
		if (n%i==0) 
		{
			ans ++;
			cout << i << " ";
		}
	cout << endl << ans << endl;
	ans = 0;
	for (int i=1;i*i<=n;i ++)
	{
		if (n%i==0) ans ++;
	} 
	cout << ans << " " << ans*2 << endl;
	return 0;
}
