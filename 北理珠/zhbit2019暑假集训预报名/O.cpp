#include <cstdio>
#include <iostream>
using namespace std;

int calc(int x,int y,int z)
{
	if (x%2) return -1;
	if (y>z) swap(y,z);
	if ((x/2)%y) return -1;
	return x/2/y+1; 
}

int main()
{
	int x,y,z;
	while (cin >> x >> y >> z)
	{
		if (x==0) break;
		if (calc(x,y,z)==-1) cout << "NO\n";else cout << calc(x,y,z) << endl;
		
	}
	
	return 0;
}
