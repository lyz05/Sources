#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int a[N],b[N],c[N],len;
string s1,s2,s3;

int main()
{
	cin >> s1 >> s2;
	for (int i=0,j=s1.length()-1;i<s1.length();i ++,j --) a[i+1] = s1[j]-'0';
	for (int i=0,j=s2.length()-1;i<s2.length();i ++,j --) b[i+1] = s2[j]-'0';

	for (int j=1;j<=s2.length();j ++)
	{
		for (int i=1;i<=s1.length();i ++)
		{
			c[i+j-1] += a[i]*b[j];
			c[i+j] += c[i+j-1]/10;
			c[i+j-1] %= 10;
		}
	}

	for (len=s1.length()+s2.length();!c[len];len --);
	for (int i=len;i;i --) cout << c[i]; 
	return 0;
} 

// 123
//  25
// 615
//246
//3075
