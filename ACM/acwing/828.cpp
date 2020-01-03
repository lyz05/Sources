#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map> 
using namespace std;

map<string,int> m;
int n;

int main()
{
	cin >> n;
	while (n --)
	{
		char c;
		string s;
		cin >> c >> s;
		if (c=='I') 
		{
			m[s] ++;
		}
		if (c=='Q') cout << m[s] << endl;
	}
	return 0;
} 
