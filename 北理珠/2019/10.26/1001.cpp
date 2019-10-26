#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int n,ans;

int main()
{
	while (cin >> n && n!=0)
	{
		for (ans=0;n;n/=2,ans ++);
		cout << ans << endl;
	}
	return 0;
}

//5
//1 2 4

//13
//1 2 4 8 
