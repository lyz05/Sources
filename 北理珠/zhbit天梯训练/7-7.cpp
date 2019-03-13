#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 10000+1005;
const char st[2][6]={" GPLT"," gplt"};
char s[N];
int a[5];
int main()
{
	scanf("%s",s);
	for (int i=0;i<(int)strlen(s);i ++)
	{
		for (int j=1;j<=4;j ++)
			if (s[i]==st[0][j] || s[i]==st[1][j]) a[j] ++;
	}
	for (int i=1;i<=4;i ++) a[0] += a[i];
	while (a[0])
	{
		for (int i=1;i<=4 && a[0];i ++)
			if (a[i])
			{
				a[i]--;a[0]--;
				printf("%c",st[0][i]);
			}
	}
	return 0;
}
