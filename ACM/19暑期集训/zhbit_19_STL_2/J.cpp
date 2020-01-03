#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

using namespace std;
const int N = 105;
int T,k,maxx,now,n,m;
int a[N];

int main()
{
	freopen("J.in","r",stdin);
	cin >> T;
	while (T --)
	{
		int ans = 0;
		cin >> n >> m;
		for (int i=0;i<n;i ++) 
			cin >> a[i];
		a[m] = -a[m];
		now = 0;
		
		while (1)
		{
			k = 0,maxx = 0;
			for (int i=now,flag=1;i!=now || flag;i=(i+1)%n)
			{
				flag = 0;
				if (abs(a[i])>maxx) maxx = abs(a[i]), k = i;
			}
			ans ++;
			if (a[k]<0) 
			{
				cout << ans << endl;
				break;
			}
			a[k] = 0;
			now = (k+1)%n;
		}
	}
	return 0;
} 
