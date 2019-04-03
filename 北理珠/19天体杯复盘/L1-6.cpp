#include <bits/stdc++.h>
using namespace std;

int T,n,x,y; 

int calc(int x)
{
	int ret = 0;
	while (x)
	{
		ret += x%10;
		x /= 10;
	}
	return ret;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		x = n/1000;
		y = n%1000;
		if (calc(x) == calc(y)) cout << "You are lucky!" << endl;
		else cout << "Wish you good luck." << endl; 
	}
}
