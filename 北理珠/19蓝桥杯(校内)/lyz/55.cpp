#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n,ans;

int main()
{
	//freopen("5.in","r",stdin);
	freopen("55.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i ++)
	{
		int x = i,tmp = 9,flag = 1;
		while (x)
		{
			int t = x%10;
			if (t>tmp) 
			{
				flag = 0;
				break;
			}
			tmp = t; 
			x /= 10;
		}
		if (flag) ans ++;
		cout << i << " " << ans << endl;
	}
	//cout << ans;
	return 0;
}
