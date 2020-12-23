#include <iostream>
#include <algorithm>
using namespace std;
int a[100000000+7],n;

int main()
{
	while (cin >> n)
	{
		long long ans;
		unsigned long long mans;
		for (int i=0;i<n;i ++)
		{
			cin >> a[i];
		}
		sort(a,a+n);
		ans = (long long)a[n-1]*a[n-2]*a[n-3];
		if (a[0]<0 && a[1]<0 && a[n-1]>0)
		{
			a[0] = -a[0];
			a[1] = -a[1];
			mans = (unsigned long long)a[0]*a[1]*a[n-1];
			if (ans<0 || mans>ans)
				cout << mans << endl;
			else
				cout << ans << endl;
			continue;
		}
		cout << ans << endl;
	}
	return 0;
}
