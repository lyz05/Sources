#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long LL;

const int N = 2e5+5;
int n,m,a[N];
stack<int> s;

LL Pow(LL x,LL y,LL mo)
{
	LL ans = 1;
	while (y)
	{
		if (y%2) ans = (ans*x)%mo;
		x=(x*x)%mo;
		y/=2;
	}
	return ans;
}

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++) 
	{
		LL x,y,mo;
		cin >> x >> y >> mo;
		cout << Pow(x,y,mo) << endl;
	} 
	return 0;
} 
