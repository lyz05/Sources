#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int a[4];

int main()
{
	//freopen("A.in","r",stdin);
	//freopen(".out","w",stdout);

	for (int i=0;i<4;i ++) cin >> a[i];
	sort(a,a+4);
	if (a[0]+a[3] == a[1]+a[2] || a[0]+a[1]+a[2] == a[3]) cout << "YES"; else cout << "NO"; 

	return 0;
}
