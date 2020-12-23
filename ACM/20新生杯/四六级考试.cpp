#include <iostream>
using namespace std;

long long n;

int main()
{
	while (cin >> n) {
		int ans = 1;
		for (int i=0;i<n;i ++)
		{
			int t;
			cin >> t;
			if (t) ans=ans*2+1; else ans*=2;		
		}
		
		cout << (char)(ans-(1<<n)+'A') << endl;
	}
	return 0;
 } 
/*
1
2 3
4 5 6 7
8 9 10 11 12 13 14 15
*/
