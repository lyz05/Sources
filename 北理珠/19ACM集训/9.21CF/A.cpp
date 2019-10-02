#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 2*1e5+7;
int n,now,ans;
char s[N];

int main()
{
	freopen("A.in","r",stdin);
	//freopen(".out","w",stdout);

	cin >> n;
	cin >> s;
	for (int i=0;i<n;i ++)
	{
		if (s[i] == 'a') now ++;
		if (s[i] == 'b') now --;
		if ((i+1)%2==0 && now!=0)
		{
			if (now>0) s[i] = 'b';
			else s[i] = 'a';
			now = 0;
			ans ++;
		}
	}
	cout << ans << endl << s << endl;
	return 0;
}
