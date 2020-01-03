#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int a[N],b[N],c[N];
string s1,s2,s3;

int main()
{
	cin >> s1 >> s2;
	for (int i=0,j=s1.length()-1;i<s1.length();i ++,j --) a[i] = s1[j]-'0';
	for (int i=0,j=s2.length()-1;i<s2.length();i ++,j --) b[i] = s2[j]-'0';
	int len = max(s1.length(),s2.length()),jw = 0;
	for (int i=0;i<len;i ++)
	{
		c[i] = a[i] + b[i] + jw;
		jw = c[i]/10;
		c[i] %= 10;
	}
	if (jw) c[len ++] = jw;
	for (int i=len-1;i>=0;i --) cout << c[i]; 
	return 0;
} 
