#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 102;
int n,m;
char s[N];

int main()
{
	while (cin >> n >> m)
	{
		for (int i=1;i<=m; i++)
		{
			int root = 1;
			cin >> s;
			for (int j=0;j<strlen(s);j ++){
				if (s[j]=='y')
					root = root<<1;
				else root = (root<<1)+1;
			}
			cout << root-(1<<n)+1 << endl;
		}
	}
	return 0;
}
