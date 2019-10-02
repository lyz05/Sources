#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 200000+8;
int n,k;
char s[N];

int main()
{
	//freopen("B.in","r",stdin);
	//freopen(".out","w",stdout);

	cin >> n >> k;
	cin >> s;
	if (k==0) cout << s << endl;
	else if (n==1) cout << "0" << endl;
	else
	{
		if (s[0]!='1') s[0] = '1',k --;
		int len = strlen(s);
		for (int i=1;i<len && k;i ++)
		{
			if (s[i]=='0') continue;
			k --;
			s[i] = '0';
		}
		cout << s << endl;
	}
	return 0;
}
