#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	//freopen("0.in","r",stdin);
	//freopen(".out","w",stdout);
	int n = 2019,ans = 0;
	for (int i=15;i>=0;i --)
		if (((1<<i)&n) != 0) 
		cout << '1';else cout <<'0';
	 
	return 0;
}
//11111100011
//11111100011
