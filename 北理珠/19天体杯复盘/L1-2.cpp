#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1005];
int tot;

int main()
{
	cin.getline(s,sizeof s);
	for (int i=0;i<=(int)strlen(s);i ++)
	{
		if (s[i]=='6') tot ++;
		else
		{
			if (tot>9) printf("27");
			else if (tot>3) printf("9");
			else if (tot>0)
				for (int j=0;j<tot;j++) printf("6");
			if (i!=strlen(s)) printf("%c",s[i]);
			tot = 0;
		}
	}
} 
