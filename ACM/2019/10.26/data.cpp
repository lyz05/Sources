#include <cstdio>
#include <>
#include <iostream>
using namespace std;

int main()
{
	int T = rand()%10;
	cout << T << endl;
	while (T --)
	{
		int n = rand()%10000;
		cout << n << endl;
		for (int i=1;i<=n;i ++)
		{
			cout << rand()%100 << " ";
		}
		cout << endl;
		for (int i=1;i<=n;i ++)
			cout << "m";
		for (int i=1;i<=n;i ++)
			cout << "z";
		cout << endl;
	}
	return 0;
}

//5
//1 2 4

//13
//1 2 4 8 
