#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int M = 1005;
int n;
char s[M];

bool judge(char s[],char st[])
{
	for (int i=0;i+strlen(st)-1<strlen(s);i ++)
	{
		bool flag = 1;
		for (int j=0;j<strlen(st);j ++)
		{
			if (s[i+j]!=st[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag) return 1;
	}
	return 0;
}

int find(char s[])
{
	int tot = 0;
	for (int i=strlen(s)-1;i>=0;i --)
	{
		if (s[i]==' ') tot ++;
		if (tot==3) return i+1;
	}
	return 0;
}

int main()
{
	freopen("L1-3.in","r",stdin);
	scanf("%d\n",&n);
	while (n --)
	{ 
		cin.getline(s,sizeof s);
		if (judge(s,"ong,") && judge(s,"ong."))
		{
			s[find(s)] = '\0';
			cout << s << "qiao ben zhong." << endl;
		} else cout << "Skipped" << endl;
	}
	
}
