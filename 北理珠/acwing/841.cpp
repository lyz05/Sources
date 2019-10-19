#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7,mo = 1e9+7;
int n,m,sum[N];
string s;

int main()
{
	cin >> n >> m;
	cin >> s;
	for (int i=0;i<s.length();i ++)
	{
		int t = 0;
		if (s[i]<='z' && s[i] >='a') t = s[i]-'a'+1;
		if (s[i]<='Z' && s[i] >='A') t = s[i]-'A'+1+26;
		if (s[i]<='9' && s[i] >='0') t = s[i]-'0'+1+26+26;
		sum[i] = ((sum[i-1]*(26+26+10))%mo + t)%mo;
	}
	while (m --)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (((sum[y1]-sum[x1-1]+mo)%mo==(sum[y2]-sum[x2-1]+mo)%mo)?"Yes":"No") << endl;
	}
	return 0;
} 
