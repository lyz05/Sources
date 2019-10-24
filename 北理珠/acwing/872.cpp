#include <cstdio>
#include <iostream>
using namespace std;

int n;
int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

int main()
{
	cin >> n;
	for (int i=1;i<=n;i ++)
	{
		int x,y;
		cin >> x >> y;
		cout << gcd(x,y) << endl;
	}
	return 0;
} 
