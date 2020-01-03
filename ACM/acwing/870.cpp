#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

const int mo = 1e9+7;
int n;
map<LL,LL> p;

int main()
{

	cin >> n;
	while (n --)
	{
		LL x;
		cin >> x;
		for (LL i=2;i*i<=x;i ++)
		{
			while (x%i==0)
			{
				x/=i;
				p[i] ++;
			}
		}
		if (x>1) p[x] ++;
	} 
	map<LL,LL>::iterator it;
	LL ans = 1;
	for (it=p.begin();it!=p.end();it ++) ans = (ans *((it->second)+1))%mo;
	cout << ans%mo << endl;
	return 0;
} 

//2=2 
//6=2*3
//8=2*2*2
//12 
