#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

LL b,p,n;

LL gcd(LL x,LL y)
{
	if (!y) return x; else return gcd(y,x%y);
}

LL ksm(LL x,LL y)
{
	LL ret = 1;
	while (y)
	{
		if (y&1) ret = (ret*x)%p;
		x = (x*x)%p;
		y/=2;
	}
	return ret;
}

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> b >> p;
		if (gcd(b,p)!=1) 
		{
			cout << "impossible" << endl;
			continue;
		}
		cout << ksm(b,p-2) << endl;
	}
	return 0;
} 

//2=2 
//6=2*3
//8=2*2*2
//12 
