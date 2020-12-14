#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 100+8,chglen=14;
const char chg[]="chi1 huo3 guo1";
char s[N][N];
int ans,k,n;
bool flag;

int main()
{
	freopen("L1-6.in","r",stdin);
	for (n=1;cin.getline(s[n],N)&&(!(s[n][0]=='.'&&s[n][1]=='\0'));n ++)
	{
		int len = strlen(s[n]);
		for (int i=0;i<len-chglen+1;i ++)
		{
			char ch = s[n][i+chglen];
			s[n][i+chglen]='\0';
			if (strcmp(s[n]+i,chg)==0)
			{
				if (ans==0) k = n;
				ans ++;
			}
			s[n][i+chglen]=ch;
		}
	}
	cout << n-1 << endl;
	if (ans==0)
		cout << "-_-#" << endl;
	else cout << k << " " << ans << endl;
	return 0;
}
