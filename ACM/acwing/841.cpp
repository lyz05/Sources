#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 1e5+7,mo = 1e9+7,M = 26+26+10;
LL n,m,sum[N];
string s;

LL pow(LL x,LL y)
{
	LL ret = 1;
	while (y)
	{
		if (y&1) ret = (ret*x)%mo;
		x = (x*x)%mo;
		y /= 2;
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	cin >> s;
	for (int i=0;i<s.length();i ++)
	{
		LL t = 0;
		if (s[i]<='z' && s[i] >='a') t = s[i]-'a'+1;
		if (s[i]<='Z' && s[i] >='A') t = s[i]-'A'+1+26;
		if (s[i]<='9' && s[i] >='0') t = s[i]-'0'+1+26+26;
		sum[i+1] = ((sum[i]*M)%mo + t)%mo;
	}
	while (m --)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		LL left = (sum[y1]-(sum[x1-1]*pow(M,y1-x1+1))%mo+mo)%mo, right = (sum[y2]-(sum[x2-1]*pow(M,y2-x2+1))%mo+mo)%mo;
		cout << (left==right?"Yes":"No") << endl;
	}
	return 0;
} 
