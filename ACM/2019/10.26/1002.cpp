#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
int n,t;

int main()
{
	while (cin >> n && n)
	{
		for (int i=1;i<=n;i ++) scanf("%d",&t);
		if (n==1) cout << "0" << endl;
		else cout << 2*n-3 << endl;
	}
	return 0;
}

//5
//1 2 4

//13
//1 2 4 8 
