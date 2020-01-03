#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

map<int,int> a;
int n, ans;

int main()
{
	cin >> n;
	while (n --)
	{
		char c;
		int x;
		cin >> c >> x;
		if (c=='I') a[x] = 1; else cout << (a[x]?"Yes":"No") << endl;
	}
	
}
