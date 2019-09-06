#include <cstdio>
#include <iostream> 
#include <cstring>
using namespace std;

int T,n,ans;

int calc(int n)
{
	int cnt = 0;
	while (n)
	{
		cnt += n%10;
		n /= 10;
	}
	return cnt;
} 

int main()
{
	cin >> T;
	while (T --)
	{
		cin >> n;
		bool flag = 0;
		for (int i=n-6*9;i<=n;i++)
		{
			if (i+calc(i)==n) 
			{
				flag = 1;
				ans = i;
				break;
			}
		}
		if (flag) cout << ans << endl; else cout << "0" << endl;
	}
	return 0;	
} 
