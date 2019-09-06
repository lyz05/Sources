#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

using namespace std;
map <string,int> mymap;

void calc(string s)
{
	string ret="";
	for (int i=0;i<(int)s.length();i ++)
	{
		if (s[i]>='A' && s[i]<='Z') s[i] += -'A'+'a';
		if (s[i]>='a' && s[i]<='z') ret += s[i];
		else 
		{
			if (ret=="") continue;
			mymap[ret] = 1;
			ret = "";
		} 
	} 
	if (ret=="") return;
	mymap[ret] = 1;
}

int main()
{
	freopen("A.in","r",stdin);
	string s1,s2;
	while (cin >> s1)
	{
		calc(s1);
	}
	for (map<string,int>::iterator it = mymap.begin();it != mymap.end();it ++)
	{
		cout << it->first << endl;	
	}
	return 0;	
} 
