#include <cstdio>
#include <iostream>
using namespace std;

template <class Type>
int BinarySearch(Type a[],const Type &x,int n){
	int l = 0,r = n-1;
	while (l<=r)
	{
		int mid = (l+r)>>1;
		if (x == a[mid])
		{
			return mid;
		}
		if (x > a[mid])
			l = mid + 1;
		else r = mid - 1;
	}
	return -1;
} 

int main()
{
	char m = 'h';
	char y[4] = {'a','b','h','x'};
	int p = BinarySearch(y,m,4);
	cout << p << endl;
	return 0;
}
