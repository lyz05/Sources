#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const char map[] = {"abcdefghijklmnopqrstuvwxyz"};
int len,n,tot;
char s[10];

int main()
{
	scanf("%d %d",&len,&n);
	int m = 1;
	for (int i=1;i<=len;i ++) m*=26;
	m -= n;
	while (len>0)
	{
		int now = m%26;
		s[-- len] = map[now];
		m /= 26;
	}
	printf("%s\n",s);
	return 0;
}
