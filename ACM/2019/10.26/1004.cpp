#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
LL x,y;
LL a,b;

int main()
{
	while (cin >> x >> y && x!=0 && y!=0)
	{
		a = (x+y)/2;
		b = (x-y)/2;
		cout << a << " " << b << endl;
	}
	return 0;
}
