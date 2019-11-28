#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 9999;
char s[N];

int judge(char ch)
{
	if ('a'<=ch && ch<='z') return 0;
	if ('A'<=ch && ch<='Z') return 1;
	return -1;
}
void modify(char &ch,int flag)
{
	if (flag) ch = ch-'a'+'A';
	else ch = ch-'A'+'a';
}

int main()
{
	//freopen("7.in","r",stdin);
	//freopen(".out","w",stdout);

	cin >> s;
	if (judge(s[0]) == 0)
		modify(s[0],1);
	for (unsigned int i=1;i<strlen(s);i ++)
	{
		if (judge(s[i]) == 1)
		{
			modify(s[i],0);
		}
	}
	cout << s << endl;
	return 0;
}
