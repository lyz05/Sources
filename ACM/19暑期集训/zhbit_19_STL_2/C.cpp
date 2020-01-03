#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>

using namespace std;
set <string> myset;
string s;

int main()
{
	freopen("C.in","r",stdin);
	while (cin >> s)
	{
		myset.insert(s);
	}
	for (set <string>::iterator it=myset.begin();it!=myset.end();it ++)
	{
		for (int i = 1;i < (*it).size();i ++)
		{
			string L,R;
			L = (*it).substr(0,i);
			R = (*it).substr(i);
			if (myset.count(L) && myset.count(R))
			{
				cout << (*it) << endl;
				break;
			}
		} 
	} 
	return 0;	
} 
