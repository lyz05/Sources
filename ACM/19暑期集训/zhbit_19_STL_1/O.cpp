#include <cstdio>
#include <iostream> 
#include <cstring>
using namespace std;

char s[512+5];
int flag;

int main()
{
	while (cin.getline(s,sizeof s))
	{
		//flag = 0;
		for (unsigned int i=0;i<strlen(s);i ++)
		{
			if (s[i]=='\"')
			{ 
				if (!flag) cout << "``"; else cout << "\'\'";
				flag ^= 1;
			}else cout << s[i];
		}
		cout << endl;
	}
	return 0;	
} 
