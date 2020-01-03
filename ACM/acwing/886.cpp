#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

const int N = 1e5+7,mo = 1e9+7;
LL p,n,a,b;
LL fact[N],infact[N];

LL ksm(LL x,LL y)
{
	LL ret = 1;
	while (y)
	{
		if (y&1) ret = (ret*x)%mo;
		x = (x*x)%mo;
		y/=2;
	}
	return ret;
}

int main()
{
	fact[0] = infact[0] = fact[1] = infact[1] = 1;
	for (int i=2;i<=N-7;i ++) 
	{
		fact[i] = (fact[i-1]*i)%mo;
		infact[i] = (infact[i-1]*ksm(i,mo-2))%mo;
	}
	
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		cout << ((fact[a]*infact[a-b])%mo*infact[b])%mo << endl; 
	}
	return 0;
} 

