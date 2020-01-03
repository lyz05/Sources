#include <iostream>
#include <stack>
using namespace std;

const int N = 1e3+7;
int n,m,k;
int s[N];

int main()
{
	freopen("L2-4.in","r",stdin);
	cin >> n >> m >> k;
	for (int i=1;i<=k;i ++)
	{
		int now = 0;
		bool flag = 1;
		s[0] = 0;
		for (int i=1;i<=n;i ++)
		{
			if (s[0]>m) flag = 0;
			while (s[0] && s[s[0]]==now+1) now ++,s[0] --;
			int t;
			cin >> t;
			if (t==now+1) 
			{
				now ++;
				continue;
			}
			s[++ s[0]] = t;
		}
		while (s[0] && s[s[0]]==now+1) now ++,s[0] --;
		flag = flag && !s[0];
		if (flag) cout << "YES" << endl; else cout << "NO" << endl;
	} 
	return 0;	
} 
