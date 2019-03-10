#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n = 0,cnt = 0;
char s[105];
double ans,m = 1;
int main()
{
	scanf("%s",s);
	if (s[0]=='-') m*=1.5,n=-1;
	if ((s[strlen(s)-1]-'0')%2==0) m*=2;
	for (int i=0;i<(int)strlen(s);i ++)
		if (s[i]=='2') cnt ++;
	n += strlen(s);
	ans = 1.0*cnt/n*m*100;
	printf("%.2f\%%",ans);
	return 0;
} 
