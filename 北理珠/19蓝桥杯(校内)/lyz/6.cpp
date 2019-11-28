#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 9999;
const char dir[] = {'a','e','i','o','u'};
char s[N];

int main()
{
	//freopen("6.in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> s;
	for (unsigned int i=0;i<strlen(s);i ++)
	{
		for (int j=0;j<5;j ++)
		{
			if (s[i]==dir[j])
			{
				cout << dir[j];
				return 0;
			}
		}
	}
	cout << 'n';
	return 0;
}
